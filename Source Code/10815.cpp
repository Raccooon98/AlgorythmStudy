#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N,M;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
		cout<< binary_search(A.begin(), A.end(), B[i])<<'\n';
	}

	return 0;
}