#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[505][505];
int N, result;


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> dp[i][j];
		}
	}
	result = dp[0][0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= i+1; ++j) {
			if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else if (j == i)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);

			result = max(result, dp[i][j]);
		}
	}


	cout << result << '\n';

	return 0;
}