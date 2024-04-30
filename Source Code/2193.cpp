//그림 직접 그려본 결과 dp문제이고 1 -> 1, 2->1, 3->2,4->3,5->5,6->8.... 피보나치형태로 된다

#include<iostream>
#include<algorithm>
using namespace std;

int N;

long long dp[100];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= N; ++i) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N] << '\n';

	return 0;
}