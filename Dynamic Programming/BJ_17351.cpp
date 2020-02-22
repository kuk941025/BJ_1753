#include <iostream>

using namespace std;
char arr[550][550];
int dp[550][550][6] = { -1 };
int N;
inline int getMax(int a, int b) { return a > b ? a : b; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> N;
	//init dp
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k < 6; k++) dp[i][j][k] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	if (arr[1][1] == 'M') dp[1][1][1] = 0;
	else dp[1][1][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1 && j == 1) continue;

			int maxS, maxValue;
			int uMax, uStat; uMax = uStat = -1;
			//check upper
			int ny = i - 1, nx = j;
			for (int k = 0; k < 5; k++) {
				if (dp[ny][nx][k] > uMax) {
					uStat = k;
					uMax = dp[ny][nx][k];
				}
			}
			if (uStat == 3 && arr[i][j] == 'A') uMax++;

			//check left
			ny = i; nx = j - 1;
			int lMax, lStat; lMax = lStat = -1;
			for (int k = 0; k < 5; k++) {
				if (dp[ny][nx][k] > lMax) {
					lStat = k;
					lMax = dp[ny][nx][k];
				}
			}
			if (lStat == 3 && arr[i][j] == 'A') lMax++;
			
			if (lMax == uMax) {
				if (arr[i][j] == 'O') {
					if (lStat == 1) lStat++;
					else lStat = 0;
					if (uStat == 1) uStat++;
					else uStat = 0;
				}
				else if (arr[i][j] == 'L') {
					if (lStat == 2) lStat++;
					else lStat = 0;
					if (uStat == 2) uStat++;
					else uStat = 0;
				}
				else if (arr[i][j] == 'A') {
					if (lStat == 3) lStat++;
					else lStat = 0;
					if (uStat == 3) uStat++;
					else uStat = 0;
				}
				else if (arr[i][j] == 'M') {
					lStat = uStat = 1;
				}
				else lStat = uStat = 0;
				dp[i][j][getMax(lStat, uStat)] = lMax;
			}
			else {
				maxValue = getMax(uMax, lMax);
				if (uMax > lMax) maxS = uStat;
				else if (uMax < lMax) maxS = lStat;
				
				if (arr[i][j] == 'O' && maxS == 1) {
					dp[i][j][2] = maxValue;
				}
				else if (arr[i][j] == 'L' && maxS == 2) {
					dp[i][j][3] = maxValue;
				}
				else if (arr[i][j] == 'A' &&  maxS == 3) {
					dp[i][j][4] = maxValue;
				}
				else if (arr[i][j] == 'M') {
					dp[i][j][1] = maxValue;
				}
				else dp[i][j][0] = maxValue;
			}

		
		}


	}

	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans = getMax(dp[N][N][i], ans);
	}
	cout << ans << "\n";

	return 0;
}