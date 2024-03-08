#include<iostream>
#include<queue>
using namespace std;

struct ball {
	int rx, ry,bx,by;
	int cnt;
};

int N, M;
char board[10][10];
//bool visr[10][10];
//bool visb[10][10];
bool vis[10][10][10][10];
queue<ball> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void move(int& rx, int& ry, int& distance, int& i) {
	while (board[rx + dx[i]][ry + dy[i]] != '#' && board[rx][ry] != 'O') {
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

//BFS
void BFS(int Rx,int Ry,int Bx,int By) {
	q.push({ Rx,Ry,Bx,By,0 });
	vis[Rx][Ry][Bx][By] = true;
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt == 10) break;
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc=0, bc=0, ncnt = cnt + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);
			if (board[nbx][nby] == 'O')continue;
			if (board[nrx][nry] == 'O') {
				cout << ncnt;
				return;
			}
			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			if (vis[nrx][nry][nbx][nby])continue;
			vis[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncnt });
		}
	}
	cout << -1;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int rx=0, ry=0, bx=0, by=0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			if (board[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	BFS(rx,ry,bx,by);
}

