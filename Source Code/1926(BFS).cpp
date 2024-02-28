#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[502][502] = { 0, };
int vis[502][502] = { 0, };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };  //탐색 방향 오 위 왼 아래
queue<pair<int, int>> q;//BFS 큐
vector<int> count_pic; //그림개수 벡터
int w = 1;

void BFS(int x, int y) {
	vis[x][y] = 1; //방문 표시
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny < 0 || nx < 0 || nx >= n || ny >= m) {
				continue;
			}
			if (board[nx][ny] == 1 && vis[nx][ny] == 0) {
				vis[nx][ny] = 1;
				w++;
				q.push(make_pair(nx, ny));
			}
		}

	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	int cnt = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				BFS(i, j);
				count_pic.push_back(w);
				cnt++;
				w = 1;
			}
		}
	}

	//int maxw = *max_element(count_pic.begin(), count_pic.end());
	sort(count_pic.begin(), count_pic.end());
	cout << cnt << '\n';
	if (count_pic.empty())
		cout << 0 << '\n';
	else
		cout << *max_element(count_pic.begin(), count_pic.end()) << '\n';

}