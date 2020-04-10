#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int N, arr[1010][3], dp[1010][3], ans = INT_MAX;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < 3; i++) {
		dp[0][i] = arr[0][i];
		for (int j = 0; j < 3; j++) {
			if (j != i) dp[0][j] = 9999;
		}

		for (int j = 1; j < N; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + arr[j][2];
		}

		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			ans = min(ans, dp[N - 1][j]);
		}
	}

	cout << ans << "\n";
	return 0;
}