//그림이나 배추문제처럼 구역 갯수 세기 (적록색약x 적록색약o->R=G 두개 나눠서)
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
using pii = pair<int, int>; //좌표용
int N,result1=0,result2=0;

vector<vector<char>> map(N, vector<char>(N, 0));
vector<vector<bool>> vis(N, vector<bool>(N, 0));//2차원벡터 선언 및 초기화방법

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };  //탐색 방향 오 위 왼 아래
queue<pii> q;

//BFS
void BFS(int a,int b) {
	q.push({ a,b });
	vis[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (vis[nx][ny] != 0) continue;
			if (map[nx][ny] != map[x][y]) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	//색맹x 탐색
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (vis[i][j] == 0) {
				BFS(i, j);
				result1++;
			}
		}
	}
	fill(vis.begin(),vis.end(),0);//다시 초기화

	//색맹o이기때문에 G->R로 변경 후 탐색
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (vis[i][j] == 0) {
				BFS(i, j);
				result2++;
			}
		}
	}

	cout << result1 << ' ' << result2;

}