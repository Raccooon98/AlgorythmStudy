//백트래킹으로 모든 계산의 경우를 찾아보고 최댓값과 최솟값을 저장한 후 출력하는 방법을 사용하면 될것 같다.

#include<iostream>
using namespace std;

int N;
int input[11];
int cal[4];
int Max = -1000000001;
int Min = 1000000001;

void Cal(int num,int idx) {
	if (idx == N) {
		if (num > Max)
			Max = num;
		if (num < Min)
			Min = num;
		return;
	}
	for (auto i = 0; i < 4; ++i) {
		if (cal[i] > 0) {
			cal[i]--;
			if (i == 0)
				Cal(num + input[idx], idx + 1);
			else if(i==1)
				Cal(num - input[idx], idx + 1);
			else if (i == 2)
				Cal(num * input[idx], idx + 1);
			else
				Cal(num / input[idx], idx + 1);
			cal[i]++;
		}
	}
	return;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	for (auto i = 0; i < N; ++i) {
		cin >> input[i];
	}
	for (auto i = 0; i < 4; ++i) {
		cin >> cal[i];
	}

	Cal(input[0], 1);

	cout << Max << '\n';
	cout << Min;
}
