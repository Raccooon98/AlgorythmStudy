//최단거리 구하기BFS +벽 부수기..
// 벽을 부순다...

#include<iostream>
#include<queue>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int N, M,K, result = 0;//N세로 M가로
int Map[1001][1001] = { 0, };
int vis[1001][1001][11] = { 0, }; // 0~10개까지 부술 수 있으므로 
queue<pair<pair<int, int>, pair<int,int>>> q;

void BFS() {
	bool breakable = 0;
	q.push({ { 0,0 }, {0,1} });
	vis[0][0][0] = 1;

	while (!q.empty()) {
		auto [x, y] = q.front().first;
		auto [k, c] = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1) {//끝지점 도착하면
			result = c;
			return;
		}

		for (auto i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny][k] == 0) {
				if (Map[nx][ny] == 1 && k < K) {//다음칸이 벽인데 부술 수 있으면
					q.push({ { nx,ny }, {k + 1,c + 1} });
					vis[nx][ny][k + 1] = 1;
				}

				if (Map[nx][ny] == 0) {//다음칸이 0이고 안지나갔으면
					q.push({ {nx,ny},{k,c + 1} });
					vis[nx][ny][k] = 1;
				}

			}
			
		}
	}

	result = -1;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> K;
	for (auto i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (auto j = 0; j < tmp.size(); ++j) {
			//문자열로 되어있기때문에 숫자로 바꿔주기
			Map[i][j] = tmp[j] - '0';
		}
	}

	BFS();
	cout << result;
}