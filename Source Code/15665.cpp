#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> input;

void dfs(int k) {
    if (k == M) {
        for (auto i = 0; i < M; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        return;
    }
    int num = -1;
    for (auto i = 1; i <= N; ++i) {
        if (num != input[i]) {
            arr.push_back(input[i]);
            num = input[i];
            dfs(k + 1);
            arr.pop_back();
        }
    }
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

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