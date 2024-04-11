//1. 택시가 먼저 태울 손님을 선정 -> 우선순위 가장 가까운사람 if 가까운사람이 둘 이상이면 행이 가장 작은사람 그사람도 둘이상이면 열이 가장 작은 사람

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, E;
int len = 1000000000;
int To;
int check = 0;

struct Taxi {
	int x, y;
	int energy;
};
Taxi taxi;

struct Person {
	int x, y;
	int fx, fy;
};
vector<Person> P;
int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

int Map[21][21];
int vis[21][21];

int bfs(int px, int py)//me 에서부터 목적지!
{
	memset(vis, 0, sizeof(vis));

	if (taxi.x == px && taxi.y == py)//목적지랑 지금위치랑 똑같을때!!
		return 0;

	vis[taxi.x][taxi.y] = 1;
	queue<pair<int, int> > q;
	q.push({ taxi.x ,taxi.y });

	int result = 0;
	while (!q.empty())
	{
		int n = q.size();
		for (int j = 0; j < n; ++j)
		{
			auto[x, y] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (vis[nx][ny] == 1) continue;
				if (Map[nx][ny] == 1) continue;//벽
				if (nx == px && ny == py)//목적지
					return result + 1;

				vis[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}

		}
		result++;
	}

	return -1;//갈수 없는 경우
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	
	cin >> N >> M >> E;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Map[i][j];
		}
	}

	int a, b;
	cin >> a >> b;
	a--; b--;
	taxi = { a,b,E };

	for (int i = 0; i < M; ++i) {
		int q, w, e, r;
		cin >> q >> w >> e >> r;
		q--; w--; e--; r--;
		P.push_back({ q,w,e,r });
	}

	while(1) {
		len = 1000000000;

		for (int i = 0; i <P.size(); ++i)
		{
			int sum = bfs(P[i].x, P[i].y);
			if (sum == -1)//갈수 없음
			{
				check = -1;
				break;
			}
			else if (len > sum)
			{
				//더 짧으면
				len = sum;
				To = i;
			}
			else if (len == sum)
			{
				if (P[To].x > P[i].y)
					To = i;

				else if (P[To].x == P[i].y)
					if (P[To].x > P[i].y)
						To = i;
			}
		}

		if (check == -1)//갈수 없는 곳이 있음
		{
			cout << -1 << '\n';
			return 0;
		}

		if (taxi.energy < To)//가야되는 거리보다 연료가 더 많이 필요
		{
			cout << -1 << '\n';
			return 0;
		}

		taxi.energy = taxi.energy - len;

		taxi.x = P[To].x;
		taxi.y = P[To].y;


		len = 1000000000;
		len = bfs(P[To].fx, P[To].fy);

		if (len == -1)//갈수 없는 길이면
		{
			cout << -1 << '\n';
			return 0;

		}
		if (len > taxi.energy)
		{
			//목적지까지 못감...
			cout << -1 << '\n';
			return 0;
		}
		//도착..
		taxi.energy = taxi.energy - len;
		taxi.x = P[To].fx;
		taxi.y = P[To].fy;
		P.erase(P.begin() + To);



		taxi.energy += len * 2;
		if (P.size() == 0)//한번은 무조건 하니까 조건 뒤에 해도 될듯
			break;
	}

	cout << taxi.energy << '\n';
	return 0;
}