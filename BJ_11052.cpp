#include <iostream>

using namespace std;
int cost[1010], dp[1010] = { 0 };
inline int getmax(int a, int b) { return a > b ? a : b; }

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> cost[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = getmax(dp[i - j] + cost[j], dp[i]);
		}
	}
	cout << dp[n];
	return 0;
}