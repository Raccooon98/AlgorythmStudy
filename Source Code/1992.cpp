//분할정복은 문제만 봐도 숨이 턱 막힌다..
//종이의 개수 문제처럼 총4칸으로쪼개서 탐색하고 간단하게 묶는 알고리즘 같음 ex) 4칸 -> 16칸 이런식으로

#include<iostream>
#include<string>
using namespace std;
int N;
int map[64][64];

void func(int x, int y, int size) {
	bool check1 = true; // 1인지 판단
	bool check0 = true; // 0인지 판단
	if (size == 1) {//한변이 1인 사각형까지 오면
		cout << map[y][x];
		return;
	}
	for (auto i = y; i < y + size; ++i) {
		for (auto j = x; j < x + size; ++j) {
			if (map[i][j] == 1)
				check0 = 0;
			else
				check1 = 0;

		}
	}
	if (check0)
		cout << 0;
	else if (check1)
		cout << 1;
	else {
		cout << "(";
		func(x, y, size / 2);
		func(x + size / 2, y, size / 2);
		func(x, y + size / 2, size / 2);
		func(x + size / 2, y + size / 2, size / 2);
		cout << ")";
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	string s;
	for (auto i = 0; i < N; ++i) {
		cin >> s;
		for (auto j = 0; j < N; ++j) {
			//cin >> map[i][j]; //입력이 1칸씩 나눠진게 아니고 각줄마다 이어져있는 문자열임
			map[i][j] = s[j] - '0';//문자열 각 원소를 정수로 바꿔서 저장(검색해봄)
		}
	}
	
	func(0, 0, N);

}