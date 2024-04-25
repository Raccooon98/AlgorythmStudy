#include<iostream>
#include<algorithm>
using namespace std;

int n, s,sum, result= 0x7fffffff;
int arr[100003];
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	//sort(arr, arr + n);

	int en = 0;
	sum = arr[0];
	for (int st = 0; st < n; ++st) {
		
		while (en < n && sum < s) {
			en++;
			if (en != n)sum += arr[en];
		}
		if (en >= n)break;
		result = min(result, en - st+1);
		sum -= arr[st];
	}

	if (result == 0x7fffffff)result=0;
	cout << result;

	return 0;


}