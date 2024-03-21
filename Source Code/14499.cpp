//주사위를 굴리는 방향을 입력받아 요구사항대로 구현하기..
//주사위가 구르는건 직접 구현해도 될듯 방향이 4개밖에 안됨

#include<iostream>
#define MAX 20
using namespace std;


int dx[5] = { 0, 1, -1, 0, 0 };//1,2,3,4로 명령이 들어오기때문에 0번 인덱스 비워주기(동서남북)
int dy[5] = { 0, 0, 0, -1, 1 };

int N, M, X, Y, K;
int Map[MAX][MAX];
int dice[6] = { 0, };//처음에 다 0이기때문에 {위, 아래, 동, 서, 남, 북}
int Order[1000];

void Move(int dir) {
	int temp = dice[0];
	if (dir == 1) {
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
	}
	else if (dir == 2) {
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
	}
	else if (dir == 3) {
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
	}
	else if (dir == 4) {
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> Y >> X >> K;

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < M; ++j) {
			cin >> Map[i][j];
		}
	}

	for (auto i = 0; i < K; ++i)
		cin >> Order[i];

	for (auto i = 0; i < K; ++i) {
		int cury = dy[Order[i]];
		int curx = dx[Order[i]];

		if (X + curx < 0 || X + curx >= M || Y + cury < 0 || Y + cury >= N)continue;

		Y += cury;
		X += curx;

		Move(Order[i]);
		cout << dice[0] << '\n';

		if (Map[Y][X] == 0)
			Map[Y][X] = dice[1];
		else {
			dice[1] = Map[Y][X];
			Map[Y][X] = 0;
		}
	}

	return 0;

}