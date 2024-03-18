//높이가 달라도 붙어있으면 같은 안전영역이니까 물보다 높으면 1 낮으면 0으로 바꿔서 영역의 갯수 세면 될듯(BFS)
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 101


using namespace std;
int N;
int Map1[MAX][MAX];
int Map2[MAX][MAX];
bool vis[MAX][MAX];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
vector<int> v;
queue<pair<int, int>> q;

void BFS(int a, int b) {
	vis[a][b] = 1;
	q.push({ a,b });

	while (!q.empty()) {
		//x,y로 안나누고 한번에 뽑기
		auto cur = q.front();
		q.pop();
		for (auto i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (Map2[nx][ny] && !vis[nx][ny]) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	int maxnum = -1;


	cin >> N;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			cin >> Map1[i][j];
			if (Map1[i][j] > maxnum)
				maxnum = Map1[i][j];
		}
	}

	for (auto n = 1; n <= maxnum; ++n) {

		//초기화
		int cnt = 0;
		for (auto i = 0; i < N; ++i) {
			for (auto j = 0; j < N; ++j) {
				Map2[i][j] = 0;	
				vis[i][j] = 0;	
			}
		}	

		//물보다 높으면1, 낮으면0
		for (auto i = 0; i < N; ++i) {
			for (auto j = 0; j < N; ++j) {
				if (Map1[i][j] < n) {
					Map2[i][j] = 0;
				}
				else
					Map2[i][j] = 1;
			}
		}


		for (auto i = 0; i < N; ++i) {
			for (auto j = 0; j < N; ++j) {
				if (Map2[i][j] == 1 && !vis[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
	}

	sort(v.begin(), v.end());
	cout << v[v.size()-1];

}