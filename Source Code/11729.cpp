#include<iostream>
using namespace std;

void hanoi(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b;//종료조건
		return;
	}
	//여기부터 잘 모르겠음

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	cout << (1 << k) - 1 << '\n';
	hanoi(1, 3, k);
}