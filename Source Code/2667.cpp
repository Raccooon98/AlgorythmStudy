#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 26
bool vis[MAX][MAX] = { 0, };
string board[MAX];
int N;
queue<pair<int, int>> q;
vector<int> w;

void BFS(int a, int b) {
	int dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 };
	int cnt = 0;	

	q.push({ a,b });
	vis[a][b] = 1;
	cnt++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (auto i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && vis[nx][ny]==false && board[nx][ny] == '1') {
				q.push({ nx,ny });
				vis[nx][ny] = true;
				//영역의 넓이 +1
				cnt++;
			}
		}
	}
	w.push_back(cnt);
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);


	cin >> N;
	for (auto i = 0; i < N; ++i) {
			cin >> board[i];
	}

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			if (board[i][j] == '1' && vis[i][j]==false) {
				BFS(i,j);
			}
		}
	}


	sort(w.begin(), w.end());

	cout << w.size() << '\n';
	for (auto num : w) {
		cout << num << '\n';
	}
	return 0;
}