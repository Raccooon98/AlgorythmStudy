// "문제 번호, 난이도" 이 형식의 자료를 보는 순간 해시 맵이 떠오름
// recommend x 는 정렬? 을 통해 해결하면 된다고 생각했는데 해시로 하려면 unorderd_map이고 이건 정렬X임 
// 그래서 그냥 map으로 이진 검색트리 만들면 될것 같다 라는 생각을 해봄.
// 나머지는 중복을 허용하지 않는 집합인 set를 사용하면 좋을것 같음
// add P L 은 insert 응용
// solved P는 find랑 erase 응용 하면 될듯
#include<iostream>
#include<map>
#include<set>
using namespace std;

int N, M;

set<pair<int,int>> arr;
map<int, int> dict;


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int P, L;
		cin >> P >> L;
		//arr.insert({ P,L });
		arr.insert({ L,P });
		dict[P] = L;
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		string order;
		cin >> order;

		if (order == "recommend") {
			int x; cin >> x;
			if (x == 1) {
				cout << (*prev(arr.end())).second << '\n';
			}
			else {
				cout << (*arr.begin()).second << '\n';
			}
		}
		else if (order == "add") {
			int P, L;
			cin >> P >> L;
			arr.insert({ L,P });
			dict[P] = L;
		}
		else {//solved
			int P;
			cin >> P;
			arr.erase({ dict[P],P });
			dict.erase(P);
		}
	}
	return 0;
}