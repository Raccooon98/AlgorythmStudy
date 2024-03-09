#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int N, M;
int input[9];
vector<int> arr;

void dfs(int k) {
    if (k == M) {
        for (auto i = 0; i < M; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else {
        for (auto i = 1; i <= N; ++i) {
            arr.push_back(input[i]);
            dfs(k + 1);
            arr.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    input[0] = 0;
    for (auto i = 1; i <= N; ++i)
        cin >> input[i];

    sort(input, input + N+1); //정렬

    dfs(0);
}