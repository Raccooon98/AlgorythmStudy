#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> arr;
bool vis[10];


void DFS(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {

		for (int i = 1; i <= N; i++) {
			arr.push_back(i);
			vis[i] = 1;
			DFS(n + 1);
			arr.pop_back();
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