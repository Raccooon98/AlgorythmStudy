#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int R, C;
string board[1001];
int visj[1001][1001] = { -1, };//지훈이 방문 배열
int visf[1001][1001] = { -1, };//불 방문 배열
queue<pair<int, int>> jq;//지훈큐
queue<pair<int, int>> fq;//불큐

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void BFS() {
	//불이 먼저 움직이고 지훈이가 가려는 길에 불이 있으면 실패
	while (!fq.empty()) {
		int x = fq.front().first;
		int y = fq.front().second;
		fq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;//지도 벗어나면 넘기기
			if (visf[nx][ny]>=0 || board[nx][ny] == '#')continue;
			visf[nx][ny] = visf[x][y] + 1;
			fq.push({ nx,ny });
		}
	}

	while (!jq.empty()) {
		int x = jq.front().first;
		int y = jq.front().second;
		jq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;//지도 벗어나면 넘기기
			if (visj[nx][ny] >= 0 || board[nx][ny] == '#')continue;
			visj[nx][ny] = visf[x][y] + 1;
			fq.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'J') {
				jq.push({ i,j });
				visj[i][j] = 0;
			}
			if (board[i][j] == 'F') {
				fq.push({ i,j });
				visf[i][j] = 0;
			}
		}
	}


}