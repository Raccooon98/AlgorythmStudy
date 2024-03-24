//각 학생들의 인덱스 값과 지목하는 학생을 받아서 저장한 후 학생이 지목하는 값을 비교, 본인이면 vis배열에서 true 다른학생을 가리키면
//체크 함수로 이동해서 다시 본인을 지목할때까지 재귀하는 함수를실행해서 팀이 만들어지는 지 확인(DFS같은 느낌으로)
//TC여러개니까 초기화 신경쓰기

#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100001

using namespace std;
using pii = pair<int, int>;
int T, n, result;
int Student[MAX];
bool vis[MAX];
bool isteam[MAX];

void check_team(int num) {
    vis[num] = 1;//방문
    int next = Student[num];//다음 인덱스

    if (!vis[next])//방문안했으면 바로 탐색
        check_team(next);

    else if (!isteam[next]) {//방문 했는데 팀 아니면
        int cur = next;
        int length = 0;

        while (cur != num) {
            isteam[cur] = 1;
            length++;
            cur = Student[cur];
        }
        length++;
        result += length;
    }
    isteam[num] = 1;
}


int main(void) {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> T;
    while (T--) {
        //초기화
        memset(vis, 0, sizeof(vis));
        memset(isteam, 0, sizeof(isteam));
        result = 0;


        cin >> n;

        for (auto i = 1; i <= n; ++i) {
            cin >> Student[i];
        }

        for (auto i = 1; i <= n; ++i) {
            if (!vis[i])
                check_team(i);
        }

        cout << n - result << '\n';
    }
}
