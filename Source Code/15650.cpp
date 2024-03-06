#include<iostream>
#include<vector>
#include<algorithm> // sort 함수를 사용하기 위해 추가

using namespace std;

int N, M;
vector<int> arr;
vector<vector<int>> result;
bool vis[10];

void DFS(int n) {
	if (n == M) {
		result.push_back(arr); // 현재 조합을 결과 벡터에 추가
		return;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				arr.push_back(i);
				vis[i] = 1;
				DFS(n + 1);
				arr.pop_back();
				vis[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	DFS(0);

	// 각 조합을 오름차순으로 정렬
	for (auto &comb : result) {
		sort(comb.begin(), comb.end());
	}
        // {2,1}->{1,2}...

	// 중복 제거 unique는 인접한 중복값을 제거하는 함수이므로 먼저 한번더
        // 정렬을 수행해 중복값들이 인접하게 만들어줌 
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	// 결과 출력
	for (auto &comb : result) {
		for (int num : comb) {
			cout << num << ' ';
		}
		cout << '\n';
	}

	return 0;
}