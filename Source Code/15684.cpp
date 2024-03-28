//사다리 구조를 이차원배열로 생각해보려고 노력했다. row를 세로선 col을 가로선이라고 하겠음 가로선을 3개까지 더 놓는 경우를 조합으로 구현해야하는데
//  가로선 끼리 이어질 수 없다 라는 점을 생각해보면 기준점에서 앞 뒤로 가로선이 존재하면 놓을 수 없다는 것을 고려해서 구현해야함..
// 백트래킹으로 구현하기
//이차원배열에 좌표넣을때 조심해야함.
//최대 최소값도 자기 자신과의 비교하는점 인지.

#include<iostream>
#include<algorithm>
using namespace std;

int N, M, H;
int result{ 100000000 };
int Map[11][31];
bool vis[11][31];

bool Check() {
	for (auto i = 1; i <= N; ++i) {
		int now = i;
		for (auto j = 1; j <= H; ++j) {
			if (vis[now][j] == 1) now += 1;
			else if (vis[now - 1][j] == 1) now -= 1;
		}

		if (now != i) return false;//자기자신의 번호로 도착하지 못했으면
	}
	return true;
}

void DFS(int idx, int num) {
	if (num >= 4) return; //가로선 3개 이상 놓는다 -> 종료

	if (Check()) {
		result = min(result, num);
		return;
	}

	for (auto i = idx; i <= H; ++i) {
		for (auto j = 1; j < N; ++j) {
			if (vis[j][i])continue;
			if (vis[j - 1][i])continue;
			if (vis[j + 1][i])continue;

			vis[j][i] = 1;
			DFS(i, num + 1);
			vis[j][i] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> H;
	for (auto i = 0; i < M; ++i) {
		int a, b;//b가 세로선
		cin >> a >> b;
		vis[b][a] = 1;//a번 가로선에서 b <-> b+1 연결 표시
	}

	DFS(1, 0);
	if (result >= 4)cout << -1;
	else cout << result << '\n';

	return 0;
}