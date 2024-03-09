//백트랙킹으로 N*N 체스판에 N개의 퀸을 서로 잡을 수 없게 배치하는 가짓수 구하기
#include<iostream>
using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt = 0;
int N;
void func(int a) {
	//종료조건
	if (a == N) {
		cnt++;
		return;
	}
	//반복할 부분
	for (auto i = 0; i < N; ++i) {
		if (isused1[i] || isused2[i+a] || isused3[a-i+N-1]) continue;
		isused1[i] = 1;
		isused2[i+a] = 1;
		isused3[a-i+N-1] = 1;
		func(a + 1);
		isused1[i] = 0;
		isused2[i + a] = 0;
		isused3[a - i + N - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	func(0);
	cout << cnt;
}