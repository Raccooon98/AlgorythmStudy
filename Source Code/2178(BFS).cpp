#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
string board[101];
int vis[101][101] = {0,};
queue<pair<int, int>> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void BFS(){
	q.push({ 0,0 });//시작점이 1,1이므로

	vis[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;//지도 벗어나면 넘기기
			if (vis[nx][ny]>0 || board[nx][ny] != '1') continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];//입력이 띄어쓰기로 구분이 안되어 있어서 원래 처럼 2차원 정수배열로 입력을 못받음
	}

	BFS();
	cout << vis[N-1][M-1];
}
