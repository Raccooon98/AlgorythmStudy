//3차원 BFS 출구까지 최단거리 구하기,  TC여러개 받는거(초기화 조심) 종료조건이  0 0 0 인듯 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct info{
	int z, y, x, t;//t는 걸린시간
};

queue<info> q;
int L, R, C, result = 0;
vector<vector<vector<char>>> building;
int dx[] = { 1,0,-1,0,0,0 };
int dy[] = { 0,-1,0,1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };


void BFS() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto i = 0; i < 6; ++i) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R || nz < 0 || nz >= L) continue;
			if (building[nz][ny][nx] == 'E') {
				result = cur.t + 1;
				return;
			}
			if (building[nz][ny][nx] == '.') {
				q.push({ nz,ny,nx,cur.t + 1 });
				building[nz][ny][nx] = 'O';
			}
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) return 0;

		result = 0;
		while (!q.empty()) q.pop();
		building.assign(L, vector<vector<char>>(R, vector<char>(C, 0)));//3차원벡터 초기화 방법, 벡터에 미리 L,R,C만큼 공간 만들기 + 0 으로 초기화 하기

		for (auto h = 0; h < L; ++h) {
			for (auto i = 0; i < R; ++i) {
				for (auto j = 0; j < C; ++j) {
					cin >> building[h][i][j];
					if (building[h][i][j] == 'S')
						q.push({ h,i,j,0 });
				}
			}
		}

		BFS();

		if (result != 0) {
			cout << "Escaped in " << result << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}

	}

	return 0;
}