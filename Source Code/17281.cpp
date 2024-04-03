#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, result=-100000000;
int baseball[52][9];
int arr[8]{ 1,2,3,4,5,6,7,8 };//순열용 배열 1번선수는 4번타자로 확정이라서 8명만 돌리면 됨

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < 9; ++j) {
			cin >> baseball[i][j];
		}
	}

	do {
		queue<int> Q;
		int ining = 0, score = 0;//1이닝부터 해도 되는데 배열을 0번인덱스 부터 받아서 편의상 0부터

		for (auto i = 0; i < 3; ++i)
			Q.push(arr[i]);
		//4번타자는 무조건 0번 인덱스인 1번선수로
		Q.push(0);
		for (auto i = 3; i < 8; ++i)
			Q.push(arr[i]);

		//정해진 이닝만큼 야구 시뮬레이션 돌리기
		while (ining < N) {
			int outcnt = 0;
			queue<int> base;
			for (auto i = 0; i < 3; ++i)
				base.push(0); //베이스 전부 더미선수로 채워주기

			while (outcnt < 3) {
				int x = Q.front();
				Q.pop();
				Q.push(x);//진루든 아웃이든 제일 뒷순위로 보내기

				if (baseball[ining][x] == 0)//아웃
					outcnt+=1;
				else {
					if (base.front() == 1)score += 1;
					base.push(1);//진루시키고
					base.pop();
					for (auto i = 0; i < baseball[ining][x] - 1; ++i) {//남은 타수만큼 앞으로 보내고 빈공간 더미로 채우기
						if (base.front() == 1)score += 1;
						base.pop();
						base.push(0);
					}
				}
			}
			ining += 1;
		}

		result = max(score, result);


	} while (next_permutation(arr, arr + 8));

	cout << result;

	return 0;
}