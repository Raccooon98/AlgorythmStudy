//산타, 루돌프 움직임 구현 -> 산타는  상우하좌 순의 우선순위가 있으니 dx dy를 선언해서 BFS 돌리는 식으로 하고
// 루돌프는 산타들이랑 거리 계산해서 우선순위 제일 높은 산타랑 좌표 비교해서 각 x,y좌표를 가까워지는 쪽으로 계산하는 방식이 나을것 같다. 
// dx,dy 8방향 굳이 탐색 안해도 될듯 
//충돌 구현, 상호작용 구현 
//턴 지나가는거 카운트 
//기절, 아웃 고려

#include<iostream>
#include<queue>
using namespace std;

struct Player {
	int id;
	int r, c;
	bool active;
	int power;
	int score;
};

vector<Player> santa;

pair<int, int> rudolf;
int N, M, P, C, D;
int Map[51][51];
int stunned[31];

int dx[] = { -1,0,1,0 }; //상 우 하 좌
int dy[] = { 0,1,0,-1 };
bool is_inside(int x, int y) { return x >= 0 && x < N&& y >= 0 && y < N; } //맵 안에 들어와있는지 나타내는 함수


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> P >> C >> D;

	cin >> rudolf.first >> rudolf.second;
	Map[rudolf.first][rudolf.second] = -1;

	vector<Player> santa(P+1);
	for (auto i = 1; i <= P; ++i) {
		cin >> santa[i].id >> santa[i].r >> santa[i].c;
		santa[i].active = 1;
		santa[i].power = D;
		santa[i].score = 0;
		Map[santa[i].r][santa[i].c] = santa[i].id;
	}

	//루돌프부터 이동
	int turn = M;
	while (--M) {
		int nearX = 10000;
		int nearY = 10000;
		int nearid = 0;
		pair<int, pair<int, int>> curlength = { (nearX - rudolf.first) * (nearX - rudolf.first) + (nearY - rudolf.second) * (nearY - rudolf.second) ,{nearX,nearY} };

		for (auto i = 0; i <= P; ++i) {
			if (santa[i].active) continue;//살아있는지
			pair<int, pair<int, int>> curlength = { (nearX - rudolf.first) * (nearX - rudolf.first) + (nearY - rudolf.second) * (nearY - rudolf.second) ,{nearX,nearY} };
			pair<int, pair<int, int>> tmplength = { (santa[i].r - rudolf.first) * (santa[i].r - rudolf.first) + (santa[i].c - rudolf.second) * (santa[i].c - rudolf.second),{santa[i].r,santa[i].c} };
			if (tmplength.first < curlength.first) {
				nearX = tmplength.second.first;
				nearY = tmplength.second.second;
				nearid = i;
			}
			else if (tmplength == curlength) { // 거리가 같으면 x좌표가 더 큰 산타로 목표를 잡기위해 좌표도 같이 저장
				if (tmplength.second.first > curlength.second.first) {
					nearX = tmplength.second.first;
					nearY = tmplength.second.second;
					nearid = i;
				}
				else if (tmplength.second.first == curlength.second.first) {
					if (tmplength.second.second > curlength.second.second) {
						nearX = tmplength.second.first;
						nearY = tmplength.second.second;
						nearid = i;
					}
				}
			}
		}

		if (nearid != 0) {
			int rx=0,ry=0;
			if (rudolf.first < nearX) rx = 1;
			else if (rudolf.first > nearX) rx = -1;

			if (rudolf.second < nearY) ry = 1;
			else if(rudolf.second > nearY) ry = -1;

			Map[rudolf.first][rudolf.second] = 0;
			rudolf.first += rx;
			rudolf.second += ry;

			//충돌하면 C만큼의 파워로 해당 산타 밀어버리기 ->nearid에 저장된 인덱스를 가지는 산타
			if (rudolf.first == santa[nearid].r && rudolf.second == santa[nearid].c) {
				stunned[nearid] = turn - M + 1; //현재라운드 +1에 못움직이니까

				int crashedX = santa[nearid].r + rx * C;
				int crashedY = santa[nearid].c + ry * C;
				int tmpX = crashedX;//밀려났을때 마지막으로 영향을 받는 좌표
				int tmpY = crashedY;

				while (Map[tmpX][tmpY]) {//착지 지점이 비어있을때까지 계속 충돌
					tmpX += rx;
					tmpY += ry;
				}
				//연쇄충돌을 어떻게 해야할지....
				while (!(crashedX == tmpX && crashedY == tmpY)) {//rx,ry 방향으로 여러번 갔으니까 날아온 산타가 착지한 지점까지 되돌아가기
					int prevX = tmpX - rx;
					int prevY = tmpY - ry;

					int tmpidx = Map[prevX][prevY];//prev에 있던 산타가 밀려서 tmp로 갔을거니까

					if (!is_inside(tmpX, tmpY))
						santa[tmpidx].active = 0;//산타죽음
					else {
						Map[tmpX][tmpY] = Map[prevX][prevY];//이전칸에있던 인덱스값을 당겨주기
						santa[tmpidx].r = tmpX;
						santa[tmpidx].c = tmpY;
					}

					tmpX = prevX;
					tmpY = prevY;

				}

				santa[nearid].score += C;
				santa[nearid].r = crashedX;
				santa[nearid].c = crashedY;

				if (is_inside(crashedX, crashedY)) {
					Map[crashedX][crashedY] = nearid;
				}
				else santa[nearid].active = 0;


			}
			
		}
		Map[rudolf.first][rudolf.second] = -1;

		for (auto i = 1; i <= P; ++i) {
			if (santa[i].active || stunned[i] >= turn - M)continue;

			int forward = 6;//방향으로 나올수 없는 값으로
			int distance = (santa[i].r - rudolf.first) * (santa[i].r - rudolf.first) + (santa[i].c - rudolf.second) * (santa[i].c - rudolf.second);
			

			for (auto d = 0; d < 4; ++d) {
				int nx = santa[i].r + dx[d];
				int ny = santa[i].c + dy[d];

				if (!is_inside(nx, ny))continue;
				if (Map[nx][ny] != 0)continue;
				
				int dist = (nx - rudolf.first) * (nx - rudolf.first) + (ny - rudolf.second) * (ny - rudolf.second);
				if (dist < distance) {
					distance = dist;
					forward = d;
				}
				
				if (forward != 6) {
					int nx = santa[i].r + dx[forward];
					int ny = santa[i].c + dy[forward];

					if (nx == rudolf.first && ny == rudolf.second) {
						stunned[i] = turn - M + 1;

						//충돌하면 방향 반대로 해주기
						int toX = -dx[forward];
						int toY = -dy[forward];

						int crashedX = nx + toX * D;
						int crashedY = ny + toY * D;
						int tmpX = crashedX;
						int tmpY = crashedY;

						//while() //연쇄충돌 처리 실패
						while (Map[tmpX][tmpY]) {//착지 지점이 비어있을때까지 계속 충돌
							tmpX += toX;
							tmpY += toY;
						}
						//연쇄충돌을 어떻게 해야할지....
						while (!(crashedX == tmpX && crashedY == tmpY)) {//rx,ry 방향으로 여러번 갔으니까 날아온 산타가 착지한 지점까지 되돌아가기
							int prevX = tmpX - toX;
							int prevY = tmpY - toY;

							int tmpidx = Map[prevX][prevY];//prev에 있던 산타가 밀려서 tmp로 갔을거니까

							if (!is_inside(tmpX, tmpY))
								santa[tmpidx].active = 0;//산타죽음
							else {
								Map[tmpX][tmpY] = Map[prevX][prevY];//이전칸에있던 인덱스값을 당겨주기
								santa[tmpidx].r = tmpX;
								santa[tmpidx].c = tmpY;
							}

							tmpX = prevX;
							tmpY = prevY;

						}

						santa[i].score += D;
						Map[santa[i].r][santa[i].c] = 0;
						if (is_inside(crashedX, crashedY))
							Map[crashedX][crashedY] = i;
						else
							santa[i].active = 0;

						santa[i].r = crashedX;
						santa[i].c = crashedY;
						

					}
					else {
						Map[santa[i].r][santa[i].c] = 0;
						santa[i].r = nx;
						santa[i].c = ny;
						Map[nx][ny] = i;
					}
				}
			}
		}

		for (auto& v : santa) {
			if(v.active)
				v.score += 1;
		}
	}

	for (auto& v : santa) {
		cout << v.score << ' ';
	}
}