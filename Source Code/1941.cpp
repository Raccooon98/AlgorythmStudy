//25명 중 7명을 뽑아서 S가 4개 이상 있을때를 구해야함 
//조합으로 7명을 뽑고 이어져있는지, S가 4개 이상인지 확인한다.
// 조합은 재귀랑 next_permutation 두가지 방법이 있음

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;


string seat[5];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int result = 0;
int pos[25] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,1, 1, 1, 1, 1, 1, 1};//조합을 사용하기 위한 배열


bool BFS(vector<pair<int, int>>& v) {
	bool vis[5][5] = { 0, };
	int Map[5][5] = { 0 , };

	for (auto c : v)
		Map[c.first][c.second] = 1; //v에 들어간 7개의 좌표를 Map에 등록

	queue<pii> q;
	q.push({ v[0].first,v[0].second });
	vis[v[0].first][v[0].second] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)continue;
			if (Map[nx][ny] == 1 && vis[nx][ny] != 1) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}

	for (auto c : v)
		if (vis[c.first][c.second] == 0) return false;

	return true;

}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	for (auto i = 0; i < 5; ++i)
		cin >> seat[i];

	do {
		vector<pii> v;

		for (auto i = 0; i < 25; ++i) {
			if (pos[i] == 1)
				v.push_back({ (i / 5),(i % 5) });
		}

		bool connect = BFS(v);//연결되어있는지 확인

		if (connect) {	
			int cnt = 0;
			for (auto c : v)
				if (seat[c.first][c.second] == 'S')cnt++;
			if (cnt >= 4)
				result++;
		}

	} while (next_permutation(pos, pos + 25));//25개중 7개를 선택하는 조합

	cout << result;
}