//게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다 -> 0,0 에서 시작 길이 1
//뱀이 움직이는 모양이 큐에 머리가 추가 꼬리가 pop 인데 사과를 먹으면 pop없이 push만 하는 모양

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

int Map[MAX][MAX];
int N, K, L;
queue<pair<int,int>> snakeq;
queue<pair<int, char>> dirq;
int dx[] = {0,-1,0,1};//오 , 위 , 왼, 아래 방향 전환 떄문에 각요소 인지 중요
int dy[] = {1,0,-1,0};


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> K;

	for (auto i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		Map[x][y] = 1;
	}

	cin >> L;
	for (auto i = 0; i < L; ++i) {
		int t;
		char d;
		cin >> t >> d;
		dirq.push({ t,d });
	}

	int dir = 0;
	//초기모양
	int nx = 1;
	int ny = 2;

	int time = 1;

	snakeq.push({ 1,1 });
	Map[1][1] = 2;//1은 사과 2는 뱀

	while (1) {
		if (nx < 1 || nx > N || ny < 1 || ny > N)break;

		if (Map[nx][ny] == 2) break;

		if (!dirq.empty()) {
			if (time == dirq.front().first) {
				if (dirq.front().second == 'L') {
					dir = (dir + 1) % 4;
				}
				else if (dirq.front().second == 'D') {
					dir = (dir + 3) % 4;
				}

				dirq.pop();
			}
		}

		if (Map[nx][ny] == 0) {
			snakeq.push({ nx,ny });
			Map[snakeq.front().first][snakeq.front().second] = 0;
			snakeq.pop();
		}
		else if (Map[nx][ny] == 1) {
			snakeq.push({ nx,ny });
		}

		Map[nx][ny] = 2;

		nx += dx[dir];
		ny += dy[dir];

		time++;
	}
	cout << time;
	return 0;
}