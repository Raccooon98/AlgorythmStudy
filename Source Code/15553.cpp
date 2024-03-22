/* 다리가 있는데 다리의 길이 W 만큼의 트럭이 동시에 지나갈수 있고, 다리의 최대 하중은 L이다
트럭별로 무게가 다르기때문에 다리를 동시에 지날수도 있고 아닐수도 있음.
큐나 벡터를 이용하면 좋을것 같음.
다리를 큐라고 생각하고 풀면 편하게 풀수 있을것 같다.
다리에 올라간다 -> push 한다 q.size가 w를 넘지 않아야하고 q에 들어온 값들의 합이L을 넘지 않도록 제한을 걸어둔채
(q에 들어간 무게가 L이 넘으면 더미 트럭을 넣어 들어오지못하게 제한하는 방법)
시뮬레이션을 돌리면 구현가능할것 같다.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;

int n, w, L, sum, result;//트럭갯수, 길이, 최대하중, 트럭 무게들을 더해줄 정수 
queue<int> q;
vector<int> bridge;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> n >> w >> L;

	for (auto i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		bridge.push_back(tmp);
	}

	//for (auto& v : bridge) {직접 참조해서 루프를 돌리려했는데 이렇게 하면 다음 벡터값을 가져오기 힘들어서 for문으로..
		
	for (auto& v : bridge) {

		while (1) {//큐가 꽉찰때까지 무게 0인 더미트럭을 넣는다.
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}

			if (v + sum <= L)
				break;
			q.push(0);
			result++;
		}

		q.push(v);
		sum += v;
		result++;//마지막은 트럭을 넣고 끝나니까 출력에서 다리 길이만큼 더해주기
	}

	cout << result+w << '\n';
}