//각 케이스별로 나이트가 지정된 좌표까지 몇번의 시도만에 도달할 수있는지 구하기(BFS인것 같음)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using pii = pair<int, int>;
int x, y, fx, fy;
int T, I;
//나이트 이동방식
int dx[] = {1 ,2 ,2,1,-1,-2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	//케이스 횟수만큼 반복
	for (auto i = 0; i < T; ++i) {
		cin >> I;
		//케이스마다 맵 초기화
		queue<pii> q;
		while (!q.empty()) q.pop();
		vector<vector<int>> map(I, vector<int>(I, 0));
		cin >> x >> y;
		map[x][y] = 1;
		
		q.push({ x,y });
		cin >> fx >> fy;
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (auto j = 0; j < 8; ++j) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				//맵 밖으로 나가는경우
				if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
				if (map[nx][ny]>=1) continue;
				map[nx][ny] = map[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
		cout << map[fx][fy] -1 << '\n';

	}