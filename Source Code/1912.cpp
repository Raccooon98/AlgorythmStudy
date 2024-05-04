#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	vector<int> dp(N), arr(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int Max = arr[0];

	for (int i = 1; i < N; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		Max = max(Max, dp[i]);
	}

	cout << Max << '\n';

	return 0;
}