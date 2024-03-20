//최단거리 구하기BFS +벽 부수기..
// 벽을 부순다...

#include<iostream>
#include<queue>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int N, M, result=0;//N세로 M가로
int Map[1001][1001] = { 0, };
int vis[1001][1001][2] = { 0, }; // vis[][][0] 벽을 부순다음 이동한 칸 수 / vis[][][1]벽을 안부수고 이동한 칸 수
queue<pair<pair<int, int>,int>> q;

void BFS() {
	q.push({ { 0,0 }, 1 });
	vis[0][0][1] = 1;

	while (!q.empty()) {
		auto cur = q.front().first;
		int breakable = q.front().second;
		q.pop();

		if (cur.first == N - 1 && cur.second == M - 1) {//끝지점 도착하면
			result = vis[cur.first][cur.second][breakable];
			return;
		}

		for (auto i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (Map[nx][ny] == 1 && breakable) {//다음칸이 벽인데 부술 수 있으면
				q.push({{ nx,ny }, 0});
				vis[nx][ny][breakable - 1] = vis[cur.first][cur.second][breakable] + 1;
			}

			else if (Map[nx][ny] == 0 && vis[nx][ny][breakable] == 0) {//다음칸이 0이고 안지나갔으면
				q.push({ {nx,ny},breakable });
				vis[nx][ny][breakable] = vis[cur.first][cur.second][breakable] + 1;
			}
		}
	}

	result = -1;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			//문자열로 되어있기때문에 숫자로 바꿔주기
			char a;
			cin >> a;
			Map[i][j] = a - '0';
		}
	}

	BFS();
	cout << result;
}