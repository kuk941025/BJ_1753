#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;
int st, tot_s;

long long dp[150][150] = { 0 };
long long solve(int d, int s) {
	unsigned long long res;
	if (d == 0) { dp[d][s] = 0; return 0; }
	if (s >= tot_s) { dp[d][s] = 1;  return 1; }

	if (dp[d][s] == -1) {
		res = solve(d + 1, s + 1) + solve(d - 1, s + 1);
		dp[d][s] = res;
	}
	else res = dp[d + 1][s + 1] + dp[d - 1][s + 1];
	return res;
}

int main() {
	cin >> st >> tot_s;
	memset(dp, -1, sizeof(dp));
	cout << solve(st, 0);
	return 0;
}