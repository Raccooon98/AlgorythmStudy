//이동방식이 2개인데 조건이 있음 K번만 말처럼 이동 가능함... 
//벽부수고 이동하기 문제처럼 말처럼 이동을 사용했는지를 체크하는 방식으로 하면 될것 같음 다른점은 벽부수기는 1번이었고 이건 K번 이라는점

#include<iostream>
#include<queue>
using namespace std;
using pii = pair<int, int>;//#define pii pair<int,int> 이렇게 써도 되는지?


struct Info {
	int x, y;
	int k;//말처럼 이동한 횟수
	int cnt;//총 횟수
};

int K, W, H;
int hdx[] = { 1 ,2 ,2,1,-1,-2,-2,-1 };
int hdy[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int Map[201][201];
int vis[201][201][31];

void BFS() {
	int cnt = 0;
	queue<Info> q;
	q.push({ 0,0,0,0 });

	for (auto i = 0; i <= K; ++i) {
		vis[0][0][i] = true;
	}

	while (!q.empty()) {
		Info cur = q.front();
		q.pop();

		if (cur.x == H - 1 && cur.y == W - 1) {
			cout << cur.cnt << '\n';
			return;
		}

		if (cur.k < K) {
			for (auto d = 0; d < 8; ++d) {
				int nx = cur.x + hdx[d];
				int ny = cur.y + hdy[d];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
				if (Map[nx][ny] || vis[nx][ny][cur.k + 1])continue;
				vis[nx][ny][cur.k + 1] = 1;
				q.push({ nx,ny,cur.k + 1,cur.cnt + 1 });
			}
		}

		for (auto d = 0; d < 4; ++d) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
			if (Map[nx][ny] || vis[nx][ny][cur.k])continue;
			vis[nx][ny][cur.k] = 1;
			q.push({ nx,ny,cur.k,cur.cnt + 1 });
		}
	}

	cout << -1;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> K >> W >> H;
	for (auto i = 0; i < H; ++i)
		for (auto j = 0; j < W; ++j)
			cin >> Map[i][j];

	BFS();
	return 0;
}