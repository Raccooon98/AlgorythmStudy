//안전영역 문제가 생각나는 문제인데 그 문제에서는 편의를 위해서 물을 제외한 지역은 1로 바꾸고 진행했었다.
//이 문제는 구역의 갯수를 세는 부분만 BFS로 하면 될것 같고
//나머지 주변에 0이 얼마나 있는지, 잠기는지 판단하는것은 재귀나 while로 구현하면 될것 같다.

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

#define MAX 300
using namespace std;

int N, M;
int Map[MAX][MAX];
int tmp[MAX][MAX];
bool vis[MAX][MAX];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (Map[nx][ny] != 0 && !vis[nx][ny]) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
}

void Melt() {
	memset(tmp, 0, sizeof(tmp));
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			if (Map[i][j] == 0)continue;
			int wcnt = 0;

			for (auto dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
				if (Map[nx][ny] == 0)
					wcnt++;
			}
			int num = Map[i][j] - wcnt;
			if (num > 0) tmp[i][j] = num;
		}
	}
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			Map[i][j]=tmp[i][j];
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			cin >> Map[i][j];
		}
	}

	int t = 0;
	while (1) {
		int cnt = 0;
		for (auto i = 0; i < N; ++i) {
			for (auto j = 0; j < M; ++j) {
				if (!vis[i][j] && Map[i][j] != 0) {
					BFS(i, j);
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			cout << 0;
			break;
		}
		else if (cnt >= 2) {
			cout << t;
			break;
		}

		t++;
		Melt();
		memset(vis, false, sizeof(vis));
	}

	return 0;
}