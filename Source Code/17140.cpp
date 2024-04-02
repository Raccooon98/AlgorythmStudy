//R,C,K<100이므로 MAX101로

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int R, C, K, result;
const int MAX = 101;
int Map[MAX][MAX];
int check[MAX];


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> R >> C >> K;
	for (auto i = 1; i <= 3; ++i) {
		for (auto j = 1; j <= 3; ++j) {
			cin >> Map[i][j];
		}
	}

	if (Map[R][C] == K) {
		cout << result<<'\n';
		return 0;
	}

	int time = 0;//초기엔 0초 3X3배열
	int x = 3, y = 3;

	while (1) {
		if (Map[R][C] == K) {
			result = time;
			break;
		}

		if (time > 100) {
			result = -1;
			break;
		}
		vector<int> Sizeofxy;//행이나 열 중에 제일 긴 요소에 맞춰야하기때문에 사이즈들을 저장할 벡터
		if (x >= y) {//행이 열보다 크기가 크거나 같으면
			for (auto i = 1; i <= x; ++i) {
				vector<pair<int, int>> v;
				memset(check, 0, sizeof(check));

				for (auto j = 1; j <= y; ++j)check[Map[i][j]]++;
				for (auto j = 1; j < MAX; ++j) {
					if (check[j] == 0)continue;
					v.push_back({ check[j],j });
				}

				sort(v.begin(), v.end());
				for (auto j = 1; j <= y; ++j) Map[i][j] = 0;
				int num = 1;


				for (auto& tmp : v) {
					Map[i][num++] = tmp.second;
					Map[i][num++] = tmp.first;
				}
				num--;

				Sizeofxy.push_back(num);
			}
			sort(Sizeofxy.begin(), Sizeofxy.end());
			y = Sizeofxy.back();
		}
		else {//반대로 열이 행보다 크면
			for (auto i = 1; i <= y; ++i) {
				vector<pair<int, int>> v;
				memset(check, 0, sizeof(check));

				for (auto j = 1; j <= x; ++j)check[Map[j][i]]++;
				for (auto j = 1; j < MAX; ++j) {
					if (check[j] == 0)continue;
					v.push_back({ check[j],j });
				}

				sort(v.begin(), v.end());
				for (auto j = 1; j <= y; ++j)Map[j][i] = 0;
				int num = 1;


				for (auto& tmp : v) {
					Map[num++][i] = tmp.second;
					Map[num++][i] = tmp.first;
				}
				num--;
				Sizeofxy.push_back(num);
			}
			sort(Sizeofxy.begin(), Sizeofxy.end());
			x = Sizeofxy.back();
		}
		time++;
	}

	cout << result << '\n';

	return 0;
}