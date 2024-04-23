#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> arr, tmp;



int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		tmp.push_back(arr[i]);
	}

	sort(tmp.begin(), tmp.end());
	vector<int> newarr;
	for (int i = 0; i < N; ++i) {
		if (i == 0) newarr.push_back(tmp[i]);
		else if(tmp[i-1]!=tmp[i]) newarr.push_back(tmp[i]);
	}

	int result = 0;
	for (auto& v:arr) {
		result = lower_bound(newarr.begin(), newarr.end(), v) - newarr.begin();
		cout << result << ' ';
	}

	return 0;


}