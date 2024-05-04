//투포인터로 합 구하면서 풀면 될듯!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, sum, cnt, st, en;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;
	vector<int> arr(N+1);

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	while (en<=N) {
		if (sum < M) {
			if (en == N)break;
			sum += arr[en++];
		}
		else if (sum == M) {
			cnt++;
			sum += arr[en++];
		}
		else {
			sum -= arr[st++];
		}
	}

	cout << cnt << '\n';

	return 0;
}