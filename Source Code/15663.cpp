#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
//vector<int> arr; // 값이 얿을때 비교가 안되고 out of range나와서 일단 배열로 구현
int arr[9] = { 0, };
vector<int> input;
bool isused[9] = { 0, };

void dfs(int k) {
	if (k == M) {
		for (auto i = 0; i < M; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		arr[k] = 0;
		return;
	}

	for (auto i = 1; i <= N; ++i) {
		if (!isused[i]) {
			if (arr[k] != input[i]) {
				if (k == 0)arr[k] = input[i];
				else if (arr[k - 1] <= input[i])arr[k] = input[i];
				else continue;
			}

			else continue;
			isused[i] = 1;
			dfs(k + 1);
			isused[i] = 0;
		}
	}
	arr[k] = 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	input.push_back(0);

	for (auto i = 0; i < N; ++i) {
		int a;
		cin >> a;
		input.push_back(a);
	}

	sort(input.begin(), input.end());
	dfs(0);

	return 0;
}