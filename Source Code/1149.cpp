#include<iostream>
#include<algorithm>
using namespace std;

int house[1005][3];
int N,result;


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;
	int a, b, c;
	house[0][0] = 0; house[0][1] = 0; house[0][2] = 0;

	for (int i = 1; i <= N; ++i) {
		cin >> a >> b >> c;
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + a;
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + b;
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + c;
	}
	result =min(house[N][1], house[N][0]);
	result = min(result, house[N][2]);
	cout << result << '\n';

	return 0;

}