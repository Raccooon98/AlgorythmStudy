//백트래킹으로 해결하는 문제 전체 치킨집 중에서 M개를 골라서(조합) 거리를 하나하나 다 측정해보고 값을 갱신해 나가면 되는 완전탐색 문제이다.
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 50
using namespace std;

int N, M, result,chicken_num;
int Map[MAX][MAX];
bool isselect[13];//치킨집 최대개수
vector<pair<int, int>> house, chicken, v;

int Distance() {
	int sum = 0;
	
	//
	for (auto i = 0; i < house.size(); ++i) {
		int x1 = house[i].first;
		int y1 = house[i].second;
		int minnum = 100000;

		for (auto j = 0; j < v.size(); ++j) {
			int x2 = v[j].first;
			int y2 = v[j].second;
			int length = abs(x2 - x1) + abs(y2 - y1);//절대값으로 거리 구하기
			minnum = min(minnum, length);
		}
		sum = sum + minnum;
	}

	return sum;
}

void func(int num, int cnt) {

	if (cnt == M) {
		result = min(result, Distance());
		return;
	}

	//치킨집 M개만큼 고르기
	for (auto i = num; i < chicken_num; ++i) {
		if (isselect[i] == true)continue;
		isselect[i] = true;
		v.push_back(chicken[i]);
		func(i, cnt + 1);
		isselect[i] = false;
		v.pop_back();
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	//최솟값 저장할때 쓸거임
	result = 100000;
	cin >> N >> M;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {

			cin >> Map[i][j];
			//치킨이랑 집 좌표 저장
			if (Map[i][j] == 1) house.push_back({ i,j });
			if (Map[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	chicken_num = chicken.size();

	func(0, 0);

	cout << result << '\n';
}