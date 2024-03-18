//문제에서 N과M시리즈 냄새가 난다 dfs 백트래킹으로 풀어도 될듯
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,S, cnt;
vector<int> input;


void DFS(int n, int m) {
	//종료조건
	if (n == N) return;
	//
	if (m + input[n] == S) cnt++;	

	DFS(n + 1, m);
	DFS(n + 1, m + input[n]);

}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> S;
	for (auto i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	cnt = 0;
	DFS(0, 0);

	cout << cnt;

	return 0;
}