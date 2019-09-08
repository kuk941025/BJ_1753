#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
inline int min(int a, int b) { return a > b ? b : a; }
int in[510] = { 0 }, sum[510] = { 0 };
int dp[510][510] = { 0 };
int main() {
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			cin >> in[i];
			sum[i] = in[i] + sum[i - 1];
		}

		for (int i = 1; i < num; i++) {
			for (int j = 1; j <= num - i; j++) {
				
				dp[j][j + i] = 987654321;
				for (int k = j; k < j + i; k++) {
					dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][num] << endl;
	}
	return 0;
}
