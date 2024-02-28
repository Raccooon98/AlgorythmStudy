#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, day=0;
int board[1001][1001] = { 0, };
//int vis[1001][1001] = { 0, };//없어도 될것 같음

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
queue<pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;//지도 벗어나면 넘기기
			if (board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;//몇일 지났는지 카운트 하기위해서
				q.push(make_pair(nx, ny));
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push(make_pair(i, j));//익은 토마토 저장 (기준점)
		}
	}
	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				cout << 0;
				return 0;
			}
			if (day < board[i][j])
				day = board[i][j];
		}
	}
	cout << day - 1 << '\n';//처음부터 안익은 토마토가 없는 경우에 0이 나와야하는데 1부터 시작하므로 1 빼주기


}