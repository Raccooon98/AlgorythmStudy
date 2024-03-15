//cctv 감시할 수 있는 구역에 표시해놓고 표시 안된 영역 갯수 세기
//cctv 가 감시할수 있는 모든 경우의 수 탐색
//노가다
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, arr[9][9], ans = INT_MAX;
vector<pair<int, int> > cctv;

void up(int arr[][9], int x, int y) {
	for (auto i = x - 1; i >= 0; --i) {

		if (arr[i][y] == 0) {
			arr[i][y] = -1;
		}
		else if (arr[i][y] == 6) {
			break;
		}
	}
}

void down(int arr[][9], int x, int y) {
	for (auto i = x + 1; i < n; ++i) {
		if (arr[i][y] == 0) {
			arr[i][y] = -1;
		}
		else if (arr[i][y] == 6) {
			break;
		}
	}
}

void Left(int arr[][9], int x, int y) {
	for (auto i = y - 1; i >= 0; --i) {
		if (arr[x][i] == 0) {
			arr[x][i] = -1;
		}
		else if (arr[x][i] == 6) {
			break;
		}
	}

}

void Right(int arr[][9], int x, int y) {
	for (auto i = y + 1; i < m; ++i) {
		if (arr[x][i] == 0) {
			arr[x][i] = -1;
		}
		else if (arr[x][i] == 6) {
			break;
		}
	}

}

void arr_init(int tmp[][9], int arr[][9]) {
	for (auto i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

}

void DFS(int arr[][9], int L) {

	int tmp[9][9];
	arr_init(tmp, arr);

	if (L == cctv.size()) {

		int cnt = 0;
		for (auto i = 0; i < n; ++i) {
			for (auto j = 0; j < m; ++j) {
				if (arr[i][j] == 0) {
					cnt++;
				}
			}
		}
		ans = min(cnt, ans);

		return;

	}
	else {
		int x = cctv[L].first;
		int y = cctv[L].second;

		if (arr[x][y] == 1) {
			up(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			down(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			Left(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

		}
		else if (arr[x][y] == 2) {
			up(tmp, x, y);
			down(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			Left(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

		}
		else if (arr[x][y] == 3) {
			up(tmp, x, y);
			Left(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			up(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			down(tmp, x, y);
			Left(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			down(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);
		}
		else if (arr[x][y] == 4) {
			up(tmp, x, y);
			down(tmp, x, y);
			Left(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			up(tmp, x, y);
			down(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);

			up(tmp, x, y);
			Left(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);


			down(tmp, x, y);
			Left(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);
		}
		else if (arr[x][y] == 5) {
			up(tmp, x, y);
			down(tmp, x, y);
			Left(tmp, x, y);
			Right(tmp, x, y);
			DFS(tmp, L + 1);
			arr_init(tmp, arr);
		}
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] > 0 && arr[i][j] <= 5) {
				cctv.push_back({ i,j });
			}
		}
	}


	DFS(arr, 0);


	cout << ans << '\n';

	return 0;
}


/*
//cctv 감시할 수 있는 구역에 표시해놓고 표시 안된 영역 갯수 세기
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int N, M;
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;

//맵을 벗어나는 탐색을 표현한 함수 (이거 사용하면 실수 줄일수 있을것 같음)
bool OOB(int a, int b) {
	return a < 0 || b < 0 || a >= N || b >= M;
}

void upd(int x, int y, int dir) {
	dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6)return;
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7;//표식 남기기 1~5까지는 카메라이므로 안됨
    }
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;
	int MN = 0;
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
			if (board1[i][j] == 0) MN++;
		}
	}

    // 1 << (2*cctv.size())는 4의 cctv.size()승을 의미.
    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) { // tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각할 것이다.
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;

        for (int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second; // tie(x, y) = cctv[i];로 쓰면 1줄로 줄일 수 있음

            if (board1[x][y] == 1) {
                upd(x, y, dir);
            }
            else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }
            else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else { // board1[x][y] == 5
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        int val = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                val += (board2[i][j] == 0);

        MN = min(MN, val);
    }
    cout << MN;
}
*/