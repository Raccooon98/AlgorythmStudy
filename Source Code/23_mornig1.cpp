//이번엔 기사들을 순서대로 입력 받음 
// 이동방향의 순서 고려하기
//충돌하면 연쇄충돌로 계속 밀어내는데 마지막으로 밀리는기사가 못움직이면 그냥 충돌 못하는걸로 간주
//명령으로 움직인 기사는 대미지X
//기사가 차지하는 칸에 함정이 있는만큼 대미지
//벽 조심, 1,1에서 시작하는거 고려


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L, N, Q;
int Map[45][45];
int dx[4] = { -1, 0, 1, 0 }; //상 우 하 좌
int dy[4] = { 0, 1, 0, -1 };

struct Info
{
	int r, c;
	int h, w;
	int k;
	int index=0;
};

vector<Info> knight,tmp_knight;
vector<pair<int, int>> Orders;

bool canMove(int r, int c) {
	return r >= 1 && r < L && c >= 1 && c < L && Map[r][c] != 2; // 이동 가능한지
}

bool Move(int idx, int dir) {
	if (knight[idx].k <= 0) return false; // 이미 죽은 경우 이동x

	int nr = knight[idx].r + dx[dir];//새 위치
	int	nc = knight[idx].c + dy[dir];

	if (!canMove(nr, nc)) return false; // 이동 불가능

	// 이동 가능한 경우
	while (true) {
		int nnr = nr + dx[dir], nnc = nc + dy[dir]; // 다음 위치 계산
		if (!canMove(nnr, nnc)) break; // 다음 위치가 이동 불가능한 경우
		if (Map[nnr][nnc] == 2) break; // 벽이 있는 경우

		// 다음 위치로 이동 가능하면
		for (auto& v : tmp_knight) {
			if (v.r == nr && v.c == nc) { // 다른 기사가 있을 경우
				if (!Move(v.index, dir)) return false; // 이동 실패한 경우 이동하지 않음
			}
		}

		// 연쇄충돌
		nr = nnr;
		nc = nnc;
	}

	// 기사의 위치 갱신
	knight[idx].r = nr;
	knight[idx].c = nc;

	return true;
}

void Damage() {
	for (auto& [r,c,h,w,k,idx] : knight) {
		if (k <= 0) continue; // 죽었으면 넘어가기

		int damage = 0;

		for (int i = r; i < r + h; ++i) {//r,c가 좌측상단이랬으니까
			for (int j = c; j < c + w; ++j) {
				if (Map[i][j] == 1) damage++; // 함정이 있으면 대미지
			}
		}

		k -= damage;

		if (k <= 0) {
			r = -1; // 죽은기사 맵에서 빼주기
			c = -1;
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> L >> N >> Q;

	for (auto i = 1; i <= L; ++i) {
		for (auto j = 1; j <= L; ++j) {
			cin >> Map[i][j];
		}
	}

	knight.assign(N,Info());
	Orders.assign(Q, { 0,0 });

	for (auto& [r,c,h,w,k,i]:knight) {
		cin >> r >> c >> h >> w >> k;
		i += 1;
	}
	tmp_knight.assign(knight.begin(), knight.end());

	for (auto& [i, d] : Orders) {
		cin >> i >> d;
	}

	for (auto& [idx, dir] : Orders) {
		if (Move(idx - 1, dir)) Damage();
	}

	int result = 0;
	for (auto& v : knight) {
		if (v.k > 0) {
			result += v.k;
		}
	}

	cout << result;

	return 0;
}