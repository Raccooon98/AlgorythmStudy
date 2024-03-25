//백트래킹? DFS로 N개중 N/2개를 뽑는 조합이다 라고 생각을 하고 팀을 구한 후 두 팀의 능력치 차이의 최솟값을 계속 저장하면 될것 같다.

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAX 21
using namespace std;

bool team[MAX];
int stats[MAX][MAX];
int N;
int Min = 10000000;

//함수가 호출될때마다 새로운 요소들이 생성되게 하도록 함수안에 선언
//vector<int> start, link;
//int start_score, link_score;

void maketeam(int idx, int num) {
	vector<int> start, link;
	int start_score = 0; int link_score = 0;
	
	if (num == (N / 2)) {
		for (auto i = 0; i < N; ++i) {
			if (team[i] == 1)
				start.push_back(i);//조합으로 뽑은 팀 
			else
				link.push_back(i);//나머지 남는 사람들 팀
		}

		for (auto i = 0; i < N/2; ++i) {
			for (auto j = 0; j < N/2; ++j) {
				start_score += stats[start[i]][start[j]];
				link_score += stats[link[i]][link[j]];
			}
		}
		Min = min(Min,abs(start_score - link_score));
		return;
	}

	for (auto i = idx; i < N; ++i) {
		if (team[i])continue;
		else {
			team[i] = 1;
			maketeam(i, num + 1);
			team[i] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			cin >> stats[i][j];
		}
	}

	maketeam(0, 0);
	cout << Min;
	return 0;
}