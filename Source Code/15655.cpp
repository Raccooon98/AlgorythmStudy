#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int N, M;
int input[9];
vector<int> arr;
bool vis[9];

void dfs(int num,int k) {
    if (k == M) {
        for (auto i = 0; i < M; ++i)// 배운거 활용
            cout << arr[i] << " ";
        cout << "\n";
    }
    else {
        for (auto i = num; i <= N; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                arr.push_back(input[i - 1]);
                dfs(i+1,k + 1);
                arr.pop_back();
                vis[i] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (auto i = 0; i < N; ++i)
        cin >> input[i];

    sort(input, input + N); //정렬

    dfs(1,0);
}