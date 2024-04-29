#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,result;
int arr[1005];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			result += arr[j];
		}
	}

	cout << result<<'\n';

	return 0;
}