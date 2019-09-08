#include <iostream>

using namespace std;
int dp[40] = { 0 };
int main() {
	int n; 
	cin >> n;
	dp[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;

		if (i >= 4) {
			for (int j = 0; j < i - 2; j += 2) {
				dp[i] += dp[j] * 2;
			}
		}
	}

	cout << dp[n];
	return 0;
}