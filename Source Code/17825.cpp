#include<iostream>
#include<algorithm>
using namespace std;

int dice[10];
int player[4];//말
int Map[35];
int score[35];
int turn[35];
bool check[35];

int result = -10000000;

void DFS(int c, int sum) {
	if (c == 10) {
		result = max(result, sum);
		return;
	}

	for (auto i = 0; i < 4; ++i) {//4개 말 돌리기
		int cur = player[i];//현재위치
		int next = cur;//갈곳
		int move_cnt = dice[c];//움직일 칸수

		if (turn[next] > 0) {//5,10,15 에서 방향전환
			next = turn[next];
			move_cnt--;
		}

		while (move_cnt--)
			next = Map[next];

		if (next != 21 && check[next])continue;//도착점 아닌데 여기 말 있으면 X

		check[cur] = 0;
		check[next] = 1;
		player[i] = next;

		DFS(c + 1, sum + score[next]);

		player[i] = cur;
		check[cur] = 1;
		check[next] = 0;

	}
}


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	for (auto i = 0; i < 21; ++i)
		Map[i] = i+1;
	Map[21] = 21;

	for (int i = 22; i < 27; i++) 
		Map[i] = i + 1;
	Map[27] = 20;
	Map[28] = 29;
	Map[29] = 30;
	Map[30] = 25;
	Map[31] = 32;
	Map[32] = 25;

	//방향 돌려주는 분기점
	turn[5] = 22; 
	turn[10] = 31; 
	turn[15] = 28;

	for (auto i = 0; i < 21; ++i)
		score[i] = i*2;//2,4,6,8...
	//나머지는 수동으로 입력
	score[22] = 13; 
	score[23] = 16; 
	score[24] = 19;
	score[25] = 25; 
	score[26] = 30; 
	score[27] = 35;
	score[28] = 28; 
	score[29] = 27; 
	score[30] = 26;
	score[31] = 22; 
	score[32] = 24;

	for (auto i = 0; i < 10; ++i)
		cin >> dice[i];

	DFS(0, 0);

	cout << result << '\n';
	return 0;
}