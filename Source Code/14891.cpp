//톱니바퀴는 string으로 입력 받아서 idx-1의 2번이 idx의 6번이랑 같은 극인지 다른 극인지 판단해서 회전 여부, 방향 결정 
//dequeu->앞뒤로 뺼수 있어서 회전 구현할때 편할것 같음(원형큐는 못쓰겠음)(아직 숙련도 부족으로 사용X)

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string gear[5];


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	int result = 0;


	for (auto i = 1; i < 5; ++i) {//1번 톱니라고 시작하기때문에 편의를 위해서 1~4까지 받기
		cin >> gear[i];
	}
	int k;
	cin >> k;
	for (auto i = 0; i < k; ++i) {//회전 횟수만큼 반복
		int rotation[5] = { 0, };
		int idx, dir;

		cin >> idx >> dir;
		rotation[idx] = dir;//현재 톱니의 회전방향 체크

		//회전시키는 톱니의 오른쪽부터 체크
		int cur = idx;
		int cur_dir = dir;
		for (auto j = cur + 1; j <= 4; ++j) {
			if (gear[cur][2] != gear[j][6]) {
				rotation[j] = -cur_dir; //반대방향으로 회전한다고 저장
				cur_dir = -cur_dir;//비교 기준이 바뀌니까 다시 방향 바꿔주기
				cur++;
			}
			else {
				rotation[j] = 0;
				break;	//회전 안함으로 바꾸면 이 오른쪽에 있는 톱니는 전부 회전x 더 볼 필요 없음
			}
		}

		//회전하는 톱니 왼쪽 체크
		cur = idx;
		cur_dir = dir;
		for (auto j = cur - 1; j > 0; --j) {
			if (gear[cur][6] != gear[j][2]) {
				rotation[j] = -cur_dir; //반대방향으로 회전한다고 저장
				cur_dir = -cur_dir;//비교 기준이 바뀌니까 다시 방향 바꿔주기
				cur--;
			}
			else {
				rotation[j] = 0;
				break;	//회전 안함으로 바꾸면 이 왼쪽에 있는 톱니는 전부 회전x 더 볼 필요 없음
			}
		}

		for (auto j = 1; j <= 4; ++j) {
			if (rotation[j] == 0) continue;
			else if (rotation[j] == 1) {//시계방향 회전
				string tmp = gear[j].substr(0, 7);//맨 마지막만 제외하고 추출 후 뒤에 이어붙이는 방식
				gear[j] = gear[j][7] + tmp;
			}
			else if (rotation[j] == -1) {//반시계 회전
				string tmp = gear[j].substr(1);//맨 앞을 제외하고 추출 후 추출된 문자열에 맨앞에 있던 걸 이어붙이기
				gear[j] = tmp+gear[j][0];
			}
		}
	}

	if (gear[1][0] == '1') result++;
	if (gear[2][0] == '1') result += 2;
	if (gear[3][0] == '1') result += 4;
	if (gear[4][0] == '1') result += 8;

	cout << result;
}