#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;

priority_queue<int,vector<int>,greater<int>> pq;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N * N; ++i) {
		int a;
		cin >> a;
		pq.push(a);
		if (pq.size() > N)pq.pop();
	}
	cout << pq.top() << '\n';

	return 0;
}