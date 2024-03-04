#include<iostream>

using namespace std;

int N, M;
int arr[10];
bool vis[10];

void DFS(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout<<'\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			arr[i] = i;
			vis[i] = 1;
			DFS(n + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	DFS(0);
}