    #include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int W, H,result,len;
int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };
struct coord {
	int x, y;
};

coord start;

char Map[20][20];
int vis[11][20][20];
vector<coord> dust;

void BFS(int idx) {
	for (auto i = 0; i < H; ++i) {
		for (auto j = 0; j < W; ++j) {
			vis[idx][i][j] = 10000;
		}
	}

	queue<coord> Q;
	Q.push(dust[idx]);
	vis[idx][dust[idx].x][dust[idx].y] = 0;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();

		for (auto d = 0; d < 4; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (Map[nx][ny] == 'x') continue;
			if (vis[idx][nx][ny] != 10000) continue;
			vis[idx][nx][ny] = vis[idx][x][y] + 1;
			Q.push({ nx, ny });
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	while (1) {
		dust.clear();
		len = 0;
		cin >> W >> H;

		if (W == 0 && H == 0)break;

		for (auto i = 0; i < H; ++i) {
			for (auto j = 0; j < W; ++j) {
				cin >> Map[i][j];
				if (Map[i][j] == 'o')start = { i,j };
				if (Map[i][j] == '*')dust.push_back({ i,j });
			}
		}
		dust.push_back(start);
		len = dust.size() - 1;

		for (auto i = 0; i <= len; ++i)
			BFS(i);

		vector<int> arr;
		for (auto i = 0; i <= len; ++i)
			arr.push_back(i);

		result = 10000;
		do {
			int d = 0;
			for (int from = len, to = 0; to < len && d < result; from = to++)
				d += vis[arr[from]][dust[arr[to]].x][dust[arr[to]].y];

			result = min(result, d);
		} while (next_permutation(arr.begin(), arr.end()));
		if (result < 10000)
			cout << result << '\n';
		else
			cout << -1 << '\n';
	}
}