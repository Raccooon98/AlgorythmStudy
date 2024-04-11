//아무리봐도 그냥 BFS문제인데 r,c 최대가 1500인게 걸린다. 시간복잡도에서 터지는것을 고려하지않으면 통과 못할것 같다.
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int R, C;
vector<string> Map;
int vis[1501][1501];


int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

struct coord { int x, y; };
vector<coord> goose;

queue<coord> wq,nwq;
coord last;
void Melt() {
	while (!wq.empty()) {
		auto [x, y] = wq.front(); wq.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if (Map[nx][ny] == 'X') {
				Map[nx][ny] = '.';
				nwq.push({ nx,ny });
			}
		}
	}
	
	
}

bool TryGoose(int x, int y) {
	//memset(vis, 0, sizeof(vis));
	queue<coord > q;//생각해보니 coord로 선언가능;
	vis[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if (Map[nx][ny] == 'X')continue;
			if (vis[nx][ny] == 1)continue;
			if (nx == goose[1].x && ny == goose[1].y)return true;

			q.push({ nx,ny });
			vis[nx][ny] = 1;
			last = { nx,ny };
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> R >> C;
	Map.resize(R);

	for (int i = 0; i < R; ++i) {
		cin >> Map[i];
		for (int j = 0; j < C; ++j) {
			if (Map[i][j] != 'X')
				wq.push({ i,j });
			if (Map[i][j] == 'L')
				goose.push_back({ i,j });
		}
	}
	last = goose[0];

	int time = 0;
	while (1) {
		if (TryGoose(last.x, last.y))//생각해보면 초기상태에서 바로 만날수도 있음
			break;

		Melt();
		wq = nwq;
		while (!nwq.empty())nwq.pop();
		time++;

	}


	cout << time << '\n';
	return 0;
}