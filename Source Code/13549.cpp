//숨바꼭질 앞뒤로 한칸씩 움직이거나(1초 소모) 현재 좌표의 두배로 이동 할 수 있음(0초 소모)
//예전에 풀었던 문제처럼 BFS로 해결 가능할듯

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N,M;
int vis[100001];
int result= 10000000;

void BFS(int n) {
	queue<pair<int, int>> q;//좌표 + 시간
	q.push({ n,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == M)
			result = min(result, cnt);
		//else if(result < cnt)continue;
		else {
			for (auto i = 0; i < 3; ++i) {
				int nx;
				if (i == 0)
					nx = x + 1;
				else if (i == 1)
					nx = x - 1;
				else if (i == 2)
					nx = x * 2;

				if (nx < 0 || nx >= 100001)continue;
				if (i == 2 && (vis[nx] > cnt || vis[nx] == -1)) {
					q.push({ nx,cnt });
					vis[nx] = cnt;//순간이동이니까 시간 경과X
				}
				else if (vis[nx] > cnt + 1 || vis[nx] == -1) {
					q.push({ nx,cnt+1 });
					vis[nx] = cnt + 1;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	memset(vis, -1, sizeof(vis));//0초일수도 있으니까 -1로 초기화
	cin >> N >> M;
		
	BFS(N);
	cout << result;

	return 0;
}