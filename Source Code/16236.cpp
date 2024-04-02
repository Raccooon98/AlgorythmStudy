//0: 빈 칸
//1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
//9 : 아기 상어의 위치

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N,result;
int Map[21][21];
int vis[21][21];
int dx[] = { -1, 0,0, 1}; // 상좌우하
int dy[] = {0, -1,1, 0};
bool Caneat = 1;
bool ate = 0;

struct Shark {
	int x, y;
	int size;
	int cnt;//먹을때마다 카운트 1씩 증가시켜서 size랑 같아지면 크기 up
};
Shark shark;

void BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push({{ shark.x,shark.y }, 0});
	vis[shark.x][shark.y] = 1;
	int tmptime = 0;//먹으러 가는데 걸린시간

	while (!q.empty()) {
		auto [x, y] = q.front().first;
		int cnt = q.front().second;

		//제일 위쪽 먹는거 고려
		if (Map[x][y] > 0 && Map[x][y] < shark.size && tmptime == cnt) {
			if ((shark.x > x) || (shark.x == x && shark.y > y)) {
				shark.x = x;
				shark.y = y;
				continue;
			}
		}
		q.pop();

		for (auto i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (vis[nx][ny])continue;
			if (Map[nx][ny] <= shark.size) {
				if (Map[nx][ny] > 0 && Map[nx][ny] < shark.size && !ate) {
					ate = 1;
					shark.x = nx;
					shark.y = ny;
					tmptime = cnt + 1;
					result += tmptime;
				}
				else {
					q.push({ {nx,ny},cnt + 1 });
					vis[nx][ny] = 1;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.cnt = 0;
				Map[i][j] = 0;
			}
		}
	}
	while (Caneat) {
		memset(vis, 0, sizeof(vis));
		BFS();
		if (ate) {
			ate = 0;//다시 안먹은상태로
			shark.cnt += 1;
			Map[shark.x][shark.y] = 0;//먹은 물고기 없애주기

			if (shark.cnt == shark.size) {
				shark.size += 1;
				shark.cnt = 0;
			}
		}
		else
			Caneat = 0;
	}

	cout << result<<'\n';
	return 0;
}