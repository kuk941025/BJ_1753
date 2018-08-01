#include <iostream>
#include <string.h>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
int dp[30][110];
int in[2][30];


int solve(int n, int k) {
	int res = 0;

	if (dp[n][k] != -1) return dp[n][k];
	if (n == 0 || k == 0) res = 0;
	else {
		res = solve(n - 1, k);
		if (k - in[0][n] > 0) res = max(res, solve(n - 1, k - in[0][n]) + in[1][n]);
	}
	dp[n][k] = res;

	return res;
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> in[0][i];
	for (int i = 1; i <= N; i++) cin >> in[1][i];

	memset(dp, -1, sizeof(dp));
	cout << solve(N, 100) << "\n";
	return 0;
}