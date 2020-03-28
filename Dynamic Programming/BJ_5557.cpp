#include <iostream>
using namespace std;
int N, ans;
int arr[110];
long dp[110][30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	N--;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> ans;

	dp[0][arr[0]] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] > 0) {
				if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	
	cout << dp[N - 1][ans] << "\n";
	return 0;
}