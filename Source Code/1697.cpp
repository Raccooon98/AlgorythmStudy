#include<iostream>
#include<queue>
using namespace std;

int N, K;
int vis[100001] = { 0, };
queue<pair<int, int>> q;

void BFS(int n) {
	while (!q.empty()) {
		int x = q.front().first;
		int sum = q.front().second;
		q.pop();
		if (x == K) {
			cout << sum;
			return;
		}

		if (x + 1 >= 0 && x + 1 < 100001 && vis[x + 1] != 1) {
			vis[x + 1] = 1;
			q.push({ x + 1,sum + 1 });
		}
		if (x - 1 >= 0 && x - 1 < 100001 && vis[x - 1] != 1) {
			vis[x - 1] = 1;
			q.push({ x - 1,sum + 1 });
		}
		if (x*2 >= 0 && x + 1 < 100001 && vis[x * 2] != 1) {
			vis[x * 2] = 1;
			q.push({ x * 2,sum + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	vis[N] = 1;
	q.push({ N,0 });
	BFS(N);
}