//건물을 오른쪽으로 90도 눕혔다고 생각하고 1차월 배역에서 문제 해결하면 될듯 
//탐색방향도 2방향 왼쪽(아래로, D 받아서 음수로 변환) 오른쪽(위로) BFS로 최단거리 구하듯이 하면 될것 같다.
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 1000001
using namespace std;

vector<int> dir;
queue<int> q;
int building[MAX] = { 0, };
bool vis[MAX];
int F, S, G, U, D;

void BFS(int start) {
	vis[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto i = 0; i < 2; ++i) {
			int nx = x + dir[i];

			if (nx <= 0 || nx > F) continue;
			if (!vis[nx]) {
				vis[nx] = true;
				q.push(nx);
				building[nx] = building[x] + 1;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> F >> S >> G >> U >> D;

	//up은 오른쪽으로 이동, down은 왼쪽으로 이동으로 생각하고 음수로 저장해주기
	dir.push_back(U); dir.push_back(-D);
	
	BFS(S);

	if (vis[G])
		cout << building[G];
	else
		cout << "use the stairs";
	
}