//일단 탐색방향을 구현하고 90도씩 반시계방향으로 회전하는 방법을 생각해보자 현재방향을 숫자로 나타내고 돌때마다 1씩 빼고 절대값을 4로 나눈 나머지가 방향을 나타내도록 하면 될듯
//탐색 할 수 있는 만큼 탐색을 하고 더이상 뒤로 갈 수 없으면 종료->재귀 
//시작점은 (r,c)
#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#define MAX 50
using namespace std;

int N, M;
int r, c, d;
int cnt;
int Map[MAX][MAX] = { 0, };
int vis[MAX][MAX] = { 0, };

//북,동,남,서
int dx[] = { -1,0,1,0 };//세로
int dy[] = { 0,1,0,-1 };//가로

void Move() {
	for (auto i = 0; i < 4; ++i) {
		int nd = abs(d + 3 - i) % 4;
		int nx = r + dx[nd];
		int ny = c + dy[nd];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || Map[nx][ny] == 1) continue;

		if (Map[nx][ny] == 0 && vis[nx][ny] == 0) {
			vis[nx][ny] = 1;
			r = nx;
			c = ny;
			d = nd;
			cnt++;
			Move();
		}
	}

	//멈추는 경우로..
	int back = abs(d + 2) % 4;
	int back_x = r + dx[back];
	int back_y = c + dy[back];

	if (back_x >= 0 || back_x <= N || back_y >= 0 || back_y <= M) {
		if (Map[back_x][back_y] == 0) {
			r = back_x;
			c = back_y;
			Move();
		}
		else {
			cout << cnt << '\n';
			exit(0);
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> r >> c >> d;

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			cin >> Map[i][j];
		}
	}

	vis[r][c] = 1;
	cnt++;

	Move();
