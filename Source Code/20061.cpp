// 다시생각해보니 
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int T, X, Y, score, last;
int GMap[6][6];
int BMap[6][6];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	for (auto i = 0; i < N; ++i) {

		cin >> T >> X >> Y;

		if (T == 1) { // 1X1 블록은 그대로 떨어짐
			int H = 0;
			while ((H <= 5) && (GMap[H][X] == 0)) {
				H++;
			};
			H--;
			GMap[H][X] = T;
		}
		else if (T == 2) { // 1X2 블록은 옆 열까지 비어있는지 확인
			int H = 0;
			while ((H <= 4) && (GMap[H][X] == 0) && (GMap[H + 1][X] == 0)) {
				H++;
			};
			H--;
			GMap[H][X] = T;
			GMap[H + 1][X] = T;
			
			
		}
		else if (T == 3) { // 2X1 블록은 밑 행까지 비어있는지 확인.
			int H = 0;
			while ((H <= 5) && (GMap[H][X] == 0) && (GMap[H][X + 1] == 0)) {
				H++;
			};
			H--;
			GMap[H][X] = T;
			GMap[H][X + 1] = T;
		}

		if (T == 1) {
			int H = 0;
			while ((H <= 5) && (BMap[H][Y] == 0)) {
				H++;
			};
			H--;
			BMap[H][Y] = T;
		}
		// 2X1인 경우에는 4행까지 따져준다.
		else if (T == 2) {
			int H = 0;
			while ((H <= 5) && (BMap[H][Y] == 0) && (BMap[H][Y + 1] == 0)) {
				H++;
			};
			H--;
			BMap[H][Y] = T;
			BMap[H][Y + 1] = T;
			
		}
		// 1X2인 경우에는 다음 열까지 따져준다.
		else if (T == 3) {
			int H = 0;
			while ((H <= 4) && (BMap[H][Y] == 0) && (BMap[H + 1][Y] == 0)) {
				H++;
			};
			H--;
			BMap[H][Y] = T;
			BMap[H + 1][Y] = T;
		}

		for (int i = 5; i >= 2; i--) {
			bool isFull = true; // i행이 블록으로 가득 차 있으면 true, 아니면 false
			for (int j = 0; j <= 3; j++) {
				if (GMap[i][j] == 0) { // 하나라도 비었다면 i행의 모든 블록을 제거하지 않는다.
					isFull = false;
					break;
				}
			}
			if (isFull) {
				score++; // i행의 블록을 모두 제거했으므로, 점수를 1점 올린다.
				for (int j = 0; j <= 3; j++) { // i행의 블록을 모두 제거
					GMap[i][j] = 0;
				}
				for (int j = (i - 1); j >= 0; j--) {
					for (int k = 0; k <= 3; k++) {
						GMap[j + 1][k] = GMap[j][k];
					}
				}
				for (int j = 0; j <= 3; j++) {
					GMap[0][j] = 0;
				}
				i++;
			}
		}

		int Cnt = 0; // 제거할 행의 개수
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 3; j++) {
				if (GMap[i][j] > 0) { // i행에 하나라도 블록이 있다면 제거할 행이 하나 늘어난다.
					Cnt++;
					break;
				}
			}
		}
		for (int i = (5 - Cnt); i >= 0; i--) {
			for (int j = 0; j <= 3; j++) {
				GMap[i + Cnt][j] = GMap[i][j];
			}
		}
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 3; j++) {
				GMap[i][j] = 0;
			}
		}

		for (int i = 5; i >= 2; i--) {
			bool isFull = true; // i행이 블록으로 가득 차 있으면 true, 아니면 false
			for (int j = 0; j <= 3; j++) {
				if (BMap[i][j] == 0) { // 하나라도 비었다면 i행의 모든 블록을 제거하지 않는다.
					isFull = false;
					break;
				}
			}
			if (isFull) {
				score++; // i행의 블록을 모두 제거했으므로, 점수를 1점 올린다.
				for (int j = 0; j <= 3; j++) { // i행의 블록을 모두 제거
					BMap[i][j] = 0;
				}
				for (int j = (i - 1); j >= 0; j--) {
					for (int k = 0; k <= 3; k++) {
						BMap[j + 1][k] = BMap[j][k];
					}
				}
				for (int j = 0; j <= 3; j++) {
					BMap[0][j] = 0;
				}
				i++;
			}
		}

		Cnt = 0; // 제거할 행의 개수
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 3; j++) {
				if (BMap[i][j] > 0) { // i행에 하나라도 블록이 있다면 제거할 행이 하나 늘어난다.
					Cnt++;
					break;
				}
			}
		}
		for (int i = (5 - Cnt); i >= 0; i--) {
			for (int j = 0; j <= 3; j++) {
				BMap[i + Cnt][j] = BMap[i][j];
			}
		}
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 3; j++) {
				BMap[i][j] = 0;
			}
		}
	}

	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (BMap[i][j] != 0) {
				last++;
			}
		}
	}

	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (GMap[i][j] != 0) {
				last++;
			}
		}
	}



	cout << score << '\n' << last << '\n';

	return 0;
}