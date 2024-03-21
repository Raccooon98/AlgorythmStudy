//그냥 TC여러개 있는 N과 M시리즈 느낌이다. N과M에서 했던것처럼 조합 구하면 될것 같다.
// TC여러개니까 초기화 신경쓰기, K에 0 입력되면 종료하기

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int S[13];
int K;
int lotto[6];//어차피 6개 다 채우면서 사용하기때문에 0으로 초기화하는 안해도 될듯

void DFS(int s, int d) {
	if (d == 6) {
		for (auto i = 0; i < 6; ++i)
			cout << lotto[i] << ' ';
		cout << '\n';
		return;
	}
	for (auto i = s; i < K; ++i) {
		lotto[d] = S[i];
		DFS(i + 1, d + 1);
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	while (1) {
		memset(S, 0, sizeof(S));//S초기화
		cin >> K;

		if (K == 0) break;//종료조건 
		
		for (auto i = 0; i < K; ++i) {
			cin >> S[i];
		}

		DFS(0, 0);
		cout << '\n';
	}

	return 0;
}