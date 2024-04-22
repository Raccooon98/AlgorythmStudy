//N이 1일때 1 , 2일때 2, 3일때 3 4일때 5. 5일때 8... 피보나치랑 같은 규칙으로 늘어나는것을 볼 수 있음.
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1100];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= N; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 10007;
	}

	cout << arr[N] << '\n';

	return 0;

}