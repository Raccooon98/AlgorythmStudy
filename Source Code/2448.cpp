//줄 수를 n이라고 했을때 n==3이면 가장 작은 삼각형임 더이상 줄일 수 없음 
#include<iostream>
using namespace std;

int k;
char triangle[3072][6143];//높이: 최대 3*2^10 , 밑변: 높이*2-1

void star(int n, int x,int y) {
	if (n == 3) {
		//첫째 줄 꼭지점
		triangle[x][y] = '*';

		//둘째 줄 양쪽
		triangle[x + 1][y - 1] = '*';
		triangle[x + 1][y + 1] = '*';

		//셋째 줄 밑변 5개찍기
		for (auto i = 0; i < 5; ++i) {
			triangle[x + 2][y - 2 + i] = '*';
		}
		return;
	}
	star(n / 2, x, y);
	star(n / 2, x+ n / 2, y- n / 2);
	star(n / 2, x+ n / 2, y+ n / 2);

}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> k;

	//공백도 나와야하기때문에 k줄만큼 공백으로 채워서 초기화
	for (auto i = 0; i < k; ++i) {
		for (auto j = 0; j < 2*k - 1; ++j) {
			triangle[i][j] = ' ';
		}
	}

	star(k, 0, k - 1);

	for (auto i = 0; i < k; ++i) {
		for (auto j = 0; j < 2 * k - 1; ++j) {
			cout<<triangle[i][j];
		}
		cout << '\n';
	}
}	