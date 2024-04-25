#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m, n;
int arr[100003];
int result = 0x7fffffff;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	int en = 0;
	for (int st = 0; st < n; ++st) { 
		while (en < n && arr[en] - arr[st] < m)en++;
		if (en >= n)break;
		result = min(result, arr[en] - arr[st]);
	}

	cout << result<<'\n';

	return 0;
}