#include<iostream>
#include<algorithm>
using namespace std;

int N;
int dp[10000000];
int arr[10000000];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;

	dp[1] = 0;

	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + 1;
		arr[i] = i - 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
			arr[i] = min(arr[i], i / 3);
		} 
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
			arr[i] = min(arr[i], i / 2);
		} 
	}
	cout << dp[N] << '\n';

	int now = N;
	while (1) {
		cout << now << ' ';
		if (now == 1)break;
		now = arr[now];
	}

	return 0;


}