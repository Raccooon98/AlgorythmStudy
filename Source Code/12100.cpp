#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using ll = long long;
using namespace std;

int board[21][21];
int N;
int maxnum=0;


void move(int num) {
	queue<int> q;

	//왼쪽
	if (num == 0) {
		for (auto i = 1; i <= N; ++i) {
			for (auto j = 1; j <= N; ++j) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}

			int tmp = 1;
			while (!q.empty()) {
				/*for (auto tmp = 1; tmp < q.size(); ++tmp) {
					int data = q.front();
					q.pop();

					if (board[i][tmp] == 0)
						board[i][tmp] = data;
					else if (board[i][tmp] == data) {
						board[i][tmp] *= 2;
					}
					else {
						board[i][tmp + 1] = data;
					} 
				}*///원하는 방식으로 작동을 안해서 다른 방법 구상

				int data = q.front();
				q.pop();
				
				if(board[i][tmp] == 0)
					board[i][tmp] = data;

				else if (board[i][tmp] == data) {
					board[i][tmp] *= 2;
					tmp++;
				}

				else {
					tmp++;
					board[i][tmp] = data;
				}
			}
		}
	}

	//오른쪽
	else if (num == 1) {
		for (auto i = 1; i <= N; ++i) {
			for(auto j = N; j >= 1; --j) {
				if (board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int tmp = N;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][tmp] == 0)
					board[i][tmp] = data;
				else if (board[i][tmp] == data) {
					board[i][tmp] *= 2;
					tmp--;
				}
				else {
					tmp--;
					board[i][tmp] = data;
				}
			}
		}
	}

	//위
	else if (num == 2) {
		for (auto j = 1; j <= N; ++j) {
			for (auto i = 1; i <= N; ++i) {
				if (board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int tmp = 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[tmp][j] == 0)
					board[tmp][j] = data;
				else if (board[tmp][j] == data) {
					board[tmp][j] *= 2;
					tmp++;
				}
				else {
					tmp++;
					board[tmp][j] = data;
				}
			}
		}
	}

	//아래
	else if (num == 3) {
		for (auto j = 1; j <= N; ++j) {
			for (auto i = N; i >= 1; --i) {
				if (board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int tmp = N;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[tmp][j] == 0)
					board[tmp][j] = data;
				else if (board[tmp][j] == data) {
					board[tmp][j] *= 2;
					tmp--;
				}
				else {
					tmp--;
					board[tmp][j] = data;
				}

			}
		}

		
	}
}

void DFS(int num) {
	if (num == 6)
		return;

	//잠시 담아놓을 임시 보드
	int tmp_board[22][22];
	for (auto i = 1; i <= N; ++i) {
		for (auto j = 1; j <= N; ++j) {
			tmp_board[i][j]=board[i][j];
		}
	}

	for (auto i = 0; i < 4; ++i) {
		move(i);
		for (auto j = 1; j <= N; ++j) {
			for (auto k = 1; k <= N; ++k) {
				if (board[j][k] > maxnum)
					maxnum = board[j][k];
			}
		}

		DFS(num + 1);

		//끝내고 다시 원상복구
		for (auto j = 1; j <= N; ++j) {
			for (auto k = 1; k <= N; ++k) {
				board[j][k] = tmp_board[j][k];
			}
		}
	}
}


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	for (auto i = 1; i <= N; ++i) {
		for (auto j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}

	DFS(1);

	cout << maxnum << '\n';

	return 0;
}