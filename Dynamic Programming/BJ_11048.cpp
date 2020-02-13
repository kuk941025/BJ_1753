#include <iostream>
#include <string.h>

using namespace std;
int dir[3][2] = { {0, 1}, {1, 0}, {1, 1} };
int N, M, arr[1010][1010];
int dp[1010][1010];
inline int getMax(int a, int b) { return a > b ? a : b; }
int main() {
	cin >> N >> M;
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = getMax(dp[i - 1][j - 1], getMax(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];
		}
	}
	cout << dp[N][M];
	return 0;
} 