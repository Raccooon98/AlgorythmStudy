// 색깔별로 4개인거 찾아서 터뜨리기 -> BFS로 4개 이상 붙어있는거찾기
//아래로 내리기, 내리고 터뜨리기, 터질때마다 연쇄++

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
using pii = pair<int, int>;


char Map[12][6];
bool vis[12][6];
int result = 0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

bool BFS(int y,int x,char color) {
	queue<pii> q;
	vector<pii> v;
	memset(vis, false, sizeof(vis));
	q.push({ y,x });
	v.push_back({ y,x });
	vis[y][x] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto i = 0; i < 4; ++i) {
			int nx = cur.second + dx[i];
			int ny = cur.first + dy[i];
			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12 || vis[ny][nx]) continue;
			if (Map[ny][nx] == color && !vis[ny][nx]) {
				q.push({ ny,nx });
				v.push_back({ ny,nx });
				vis[ny][nx] = 1;
			}
		}
	}

	//같은색이 4개이상이면 부수기
	int vsize = v.size();
	if (vsize >= 4) {
		for (auto i = 0; i < vsize; ++i) {
			//위에서 좌표 순서를 바꿔줬기때문에 여기는 second first 바꿀 필요가 없음
			Map[v[i].first][v[i].second] = '.';
		}
		return true;
	}

	return false;
}

void down() {
	for (auto i = 0; i < 6; ++i) {
		queue<char> q;

		for (auto j = 11; j >= 0; --j) {
			if (Map[j][i] != '.')
				q.push(Map[j][i]);
		}
		
		int num = q.size();
		for (auto j = 11; j >= 12 - num; --j) {
			Map[j][i] = q.front();
			q.pop();
		}
		for (auto j = 11 - num; j >= 0; --j) {
			Map[j][i] = '.';
		}
	}
}



int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	for (auto i = 0; i < 12; ++i) {
		string s;
		cin >> s;

		for (auto j = 0; j < 6; ++j) {
			Map[i][j] = s[j];
		}
	}

	while (1) {
		int check = 0;//더이상 진행이 안되면 안올라서 break하기

		for (auto i = 0; i < 12; ++i) {
			for (auto j = 0; j< 6; ++j) {
				if (Map[i][j] != '.') {
					if (BFS(i, j, Map[i][j])) {
						check++;
					}
				}
			}
		}

		if (check == 0) break;
		else {
			result++;
			down();
		}
	}

	if (result)
		cout << result;
	else if (result == 0)
		cout << 0;

	return 0;
}