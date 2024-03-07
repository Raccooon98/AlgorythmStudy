#include<iostream>
#include<queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int T, N, M, K = 0;
int map[50][50] = { 0, };
bool vis[50][50] = { 0, };
queue<pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		vis[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (!vis[nx][ny] && map[nx][ny] == 1) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		while (!q.empty()) q.pop();
		for (int q = 0; q < N; q++) {
			for (int k = 0; k < M; k++) {
				vis[q][k] = 0;
				map[q][k] = 0;
			}
		}
		cin >> M >> N >> K;
		int cnt = 0;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !vis[i][j]) {
					q.push({ i,j });
					BFS();
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}