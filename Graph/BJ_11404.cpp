#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
inline int getMin(int a, int b) { return a > b ? b : a; }
int dp[110][110], N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		dp[a - 1][b - 1] = getMin(dp[a - 1][b - 1], c);
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) continue; 
				
				dp[i][j] = getMin(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dp[i][j] == INT_MAX ? cout << 0 << ' ' : cout << dp[i][j] << ' ';
		cout << "\n";
	}

	return 0;
}