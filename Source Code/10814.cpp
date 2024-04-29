#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<string> arr[205];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		string b;
		cin >> a >> b;
		arr[a].push_back(b);
	}

	for (int i = 0; i < 205; ++i) {
		for (auto& name : arr[i]) {
			cout << i << ' ' << name << '\n';
		}
	}
	return 0;
}