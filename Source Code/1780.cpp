//저번에 숫자 위치 구한문제랑 비슷한 느낌 분할정복,재귀로 -1,0,1로만 된 종이 갯수 구하기
#include<iostream>
#include<vector>

using namespace std;

int N;
int rect[2200][2200];
bool check = true;
int num1 = 0, num2 = 0, num3 = 0;

void func(int x, int y, int size) {
	for (auto i = y; i < size; ++i) {
		for (auto j = x; j < size; ++j) {
			if (rect[i][j] != rect[y][x]) {//0,3에서 탐색하면 rect[3][0]으로 들어가야함
				check = false;//원소가 같은지 확인 하나라도 다르면 탈출
				break;
			}
		}
		if (!check) break;
	}
	if (!check) {
		//9개의 사각형으로 나눠서 다시 탐색...
		func(x, y, size / 3);
		func(x + size / 3, y, size / 3);
		func(x + (size / 3) * 2, y, size / 3);
		func(x, y + size / 3, size / 3);
		func(x, y + (size / 3) * 2, size / 3);
		func(x + size / 3, y + size / 3, size / 3);
		func(x + (size / 3)*2, y + size / 3, size / 3);
		func(x + size / 3, y + (size / 3)*2, size / 3);
		func(x + (size / 3) * 2, y + (size / 3)*2, size / 3);
	}
	else {
		if (rect[y][x] == -1) {
			num1++;
		}
		else if (rect[y][x] == 0) {
			num2++;
		}
		else {
			num3++;
		}
	}
}

int main(void) {
	cin >> N;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			cin >> rect[i][j];
		}
	}
	//처음 탐색을 시작하는 위치 입력
	func(0, 0, N);
	cout << num1 << '\n' << num2 << '\n' << num3 << '\n';
}