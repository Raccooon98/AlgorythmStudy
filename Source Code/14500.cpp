//테트로미노를 하나하나 놓아보고 판단한다... -> DFS? 백트래킹?
//블록들 모양이 T자 블록 빼고 나머지는 DFS로 탐색이 가능한 모양인데..
//T자블록만 따로 탐색을 구현하고 나머지는 DFS로 해결하면 될것 같은 문제 -> 생각보다는 어려움
//T자 블록은 세방향만 탐색하면 되는데 그렇게 하려면 직접 세방향을 보는 것을 네번 반복해야 하므로 네방향중 제일 작은 값을 버리는 방법을 사용.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, result = 0;
int Map[501][501];
int vis[501][501];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DFS(int x, int y, int num, int sum) {
	if (num == 4) {
		result = max(result, sum);
	}
	else {
		for (auto i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (vis[nx][ny])continue;
			vis[nx][ny]++;
			DFS(nx, ny, num + 1, sum + Map[nx][ny]);
			vis[nx][ny]--;
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N >> M;
	for (auto i = 0; i < N; ++i)
		for (auto j = 0; j < M; ++j)
			cin >> Map[i][j];

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			vis[i][j]++;
			DFS(i, j, 1, Map[i][j]);
			vis[i][j]--;
		}
	}

	//T형 블록은 가운데를 중심으로 세 방향을 탐색 - > 네방향중에 제일 작은값을 버리고 나머지 세개랑 가운데만 더하기
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			int tmp = Map[i][j];//T자블록 가운데
			int tmpMin = 1000000;

			for (auto dir = 0; dir < 4; ++dir) {
				tmpMin = min(Map[i + dx[dir]][j + dy[dir]],tmpMin);
				tmp += Map[i + dx[dir]][j + dy[dir]];
			}
			result = max(result, tmp - tmpMin);
		}
	}
	cout << result;
	return 0;
}