#include<iostream>
#include<algorithm>
#include<vector>
using ll = long long;
using namespace std;

int n, k;
int arr[10003];

bool check(ll x) {
	ll cur = 0;
	for (int i = 0; i < k; ++i) {
		cur += arr[i] / x;
	}
	return cur >= n;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> k >> n;
	for (int i = 0; i < k; ++i) cin >> arr[i];

	ll st = 1;
	ll en = 0x7fffffff; //길이 최대값이 2^31-1이기때문에

	while (st < en) {
		ll mid = (st + en+1) / 2;
		if (check(mid))st = mid;
		else en = mid - 1;
	}
	cout << st;

	return 0;
}