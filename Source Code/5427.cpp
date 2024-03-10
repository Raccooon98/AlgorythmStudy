//불!문제랑 비슷한 방식으로 구현 시도 BFS

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using pii = pair<int,int>;
int w, h, T,cnt=0;
char map[1001][1001];//원래string 으로 받으려 했는데 @ * 판단해서 불, 상근 큐에 추가하기 위해 char로 받음
int fvis[1001][1001] = {0,};
int svis[1001][1001] = {0,};
// 드디어 상하좌우
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue<pii> fq;
queue<pii> sq;

void BFS() {
	while (!fq.empty()) {
		int x = fq.front().first;
		int y = fq.front().second;
		fq.pop();
		for (auto i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (map[nx][ny] == '#' || fvis[nx][ny] != 0) continue;
			fvis[nx][ny] = fvis[x][y] + 1;
			fq.push({ nx,ny });
		}
	}

	while (!sq.empty()) {
		int x = sq.front().first;
		int y = sq.front().second;
		sq.pop();
		for (auto i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (map[nx][ny] == '#' || map[nx][ny] == '*') continue;
			if (svis[nx][ny] != 0) continue;
			if ((svis[x][y] + 1 >= fvis[nx][ny])) continue;
			svis[nx][ny] = svis[x][y] + 1;
			sq.push({ nx,ny });
		}
	}
}

int main(void) {
	cin >> T;
	while (T--) {//테스트 케이스만큼 돌리기 for문말고 while루프
		cin >> w >> h;
		for (auto i = 0; i < h; ++i) {
			for (auto j = 0; j < w; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					sq.push({ i,j });
					svis[i][j] = 1;
				}
					
				else if (map[i][j] == '*') {
					fq.push({ i,j });
					fvis[i][j] = 1;
				}
			}
		}
		BFS();
		if (cnt <= 0)
			cout << "IMPOSSIBLE" << '\n';
		cout << cnt<<'\n';
		//초기화
		memset(map, '.', sizeof(map));
		while (!fq.empty())
			fq.pop();
		while (!sq.empty())
			sq.pop();
		cnt = 0;
	}
}