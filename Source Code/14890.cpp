//경사로를 놓고 갈 수 있거나 길의 높이가 같아 평평한 경우를 길로 카운트 한다.
//경사로는 높이가 1 차이나는 경우만 놓을 수 있고, 길이가  L이며, 겹칠 수 없음.
//탐색은 2N번 직선으로 하면되는데 어떻게 구현할지 고민해봐야함 (땅의 높이 차이가 1일때 같을때 2 이상일때)
//한 방향으로 한줄씩 탐색하는것을 두번 (맵을 2개로 만들어서 [i][j], [j][i] 로 만들면 하나의 탐색방법으로 두가지 다 볼 수 있음

#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int N, L, result;
int Map1[101][101];
int Map2[101][101];

void Checkroad(int Map[][101]) {//가로방향으로 탐색
	for (auto i = 0; i < N; ++i) {
		bool check{ true };
		bool slope[101]{ 0 };

		for (auto j = 0; j < N-1; ++j) {//마지막길은 다음길이 없어서 안봄
			if (abs(Map[i][j] - Map[i][j+1]) > 1) {//높이차이가 1이상이면 이 줄 버리고 다음줄로
				check = false;
				break;
			}

			if (Map[i][j] - Map[i][j + 1] == 1) {//높은곳에서 낮은곳으로 경사 놓을때
				int height = Map[i][j + 1];
				for (auto h = j + 2; h < j + 1 + L; ++h) {//j+2번째 블록이 바로 높이가 다른 블록이거나 끝일 경우 break
					if (h >= N || Map[i][h] != height) {
						check = false;
						break;
					}
				}
				if (check) {
					for (auto l = 1; l <= L; ++l) {
						slope[j + l] = 1;//경사로 설치 체크
					}
				}
				else
					break;
			}

			if (Map[i][j] - Map[i][j + 1] == -1) {//낮은곳에서 높은곳
				int height = Map[i][j];
				for (auto h = j; h > j - L; --h) {//왼쪽에서 오른쪽으로 간다는 조건에서 왼쪽이 끝을 넘거나 높이가 다른 땅일 경우
					if (h < 0 || Map[i][h] != height||slope[h]) {//이미 경사로를 놨을경우
						check = false;
						break;
					}
				}
				if (check)
					slope[j] = 1;
				else
					break;
			}
		}
		if (check)
			result++;
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> L;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			cin >> Map1[i][j];
			Map2[j][i] = Map1[i][j];
		}
	}

	Checkroad(Map1);
	Checkroad(Map2);
			
	cout << result << '\n';
	return 0;
}