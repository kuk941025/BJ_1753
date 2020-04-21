#include <iostream>

using namespace std;
int N, M, dp[1100][1100], arr[1100][1100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	while (M--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		cout << dp[c][d] - (dp[c][b - 1] + dp[a - 1][d] - dp[a - 1][b - 1]) << "\n";
	}
	return 0;
}