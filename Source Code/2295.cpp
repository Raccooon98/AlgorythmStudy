#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, result;
vector<int> arr;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end());
	vector<int> sum;
	for (int x = 0; x < N; ++x) {
		for (int y = x; y < N; ++y) {
			sum.push_back(arr[x] + arr[y]);
		}
	}
	sort(sum.begin(), sum.end());

	for (int x = N-1; x > 0; --x) {
		for (int y = 0; y < x; ++y) {
			if(binary_search(sum.begin(),sum.end(),arr[x]-arr[y]))
				result = max(result,arr[x]);
		}
	}
	cout << result << '\n';

	return 0;
}