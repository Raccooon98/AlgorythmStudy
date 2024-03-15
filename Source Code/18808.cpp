//N이 세로 M이 가로, 아이디어1. 스티커를 구조체로 만들어서 받기 2. k번 만큼 루프 돌리면서 스티커 별로 탐색하기(일단 이걸로)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int notebook[41][41] = { 0, };
int N, M, K, R, C;

//시계방향으로 90도 회전하기
void rotate(vector<pii>& v,int& R,int& C) {
	for (auto i = 0; i < v.size(); ++i) {
		int nx = v[i].second;
		int ny = (R - 1) - v[i].first;
		v[i].first = nx; 
		v[i].second = ny;
	}
	int tmp = R;
	R = C;
	C = tmp;
}

bool func(vector<pii>& v) {
	bool check = false;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			check = true;
			for (auto c : v) {
				int nx = c.first + i;
				int ny = c.second + j;

				//범위를 벗어나거나 이미 스티커가있으면 false
				if (notebook[i][j] == 1 || nx < 0 || ny < 0 || nx >= N || ny >= M) check = false;
				
			}
			if (check) {
				for (auto c : v) {
					int nx = c.first + i;
					int ny = c.second + j;
					if(notebook[nx][ny]!=1) notebook[nx][ny] = 1;
				}
				return true;
			}
		}
	}
	return false;
}


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> K;
	while (K--) {
		int sticker[11][11] = { 0, };
		cin >> R >> C;

		//스티커 입력
		for (auto i = 0; i < R; ++i) {
			for (auto j = 0; j < C; ++j) {
				cin >> sticker[i][j];
			}
		}

		//좌표 저장
		vector<pii> v;
		for (auto i = 0; i < R; ++i) {
			for (auto j = 0; j < C; ++j) {
				if (sticker[i][j] == 1)v.push_back({ i,j });
			}
		}

		//4번 돌려기 (못붙이면 버리는거)
		for (auto i = 0; i < 4; ++i) {
			if (func(v))
				break;
			else
				rotate(v,R,C);
		}

	}
	int result = 0;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			if (notebook[i][j] == 1) result++;
		}
	}
	cout << result << '\n';

}