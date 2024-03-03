#include <iostream>

using namespace std;

int N, r, c;
int x, y, ans;

void func(int x, int y, int n) {

    if (x == r && y == c) {
        cout << ans << "\n";
        return;
    }


    if (r < x + n && r >= x && c < y + n && c >= y)
    {
        func(x, y, n / 2);
        func(x, y + n / 2, n / 2);
        func(x + n / 2, y, n / 2);
        func(x + n / 2, y + n / 2, n / 2);
    }
    // (r,c)가 현재 사분면이 아니면 그냥 사분면의 크기만큼 더해준다 (탐색한걸로 친다)
    else ans += n * n;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> r >> c;

    func(0, 0, (1 << N));//탐색하고자 하는 사분면의 왼쪽 위 좌표 기입

    return 0;
}