#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

long long result; //1000000X300000 = 300,000,000,000 이라서

//struct Jewel {
//	int cost, weight;
//};

int n, k;
pair<int,int> jewel[300005];
multiset<int> box;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> jewel[i].second >> jewel[i].first;
	}
	sort(jewel, jewel + n);

	
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		box.insert(x);
	}

	for (int i = n - 1; i >= 0; --i) {
		auto& [v, m] = jewel[i];
		auto it = box.lower_bound(m);
		if (it == box.end())continue;
		result += v;
		box.erase(it);
	}

	cout << result;

	return 0;

}