#include <iostream>
#include <limits.h>

using namespace std;
int N, arr[1010] = { 0 }, dp[1010] = { 0 };
int ans = INT_MIN;
inline int getMax(int a, int b) { return a > b ? a : b; }
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];


	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && cnt < dp[j]) {
				cnt = dp[j];
			}
		}

		dp[i] = cnt + 1;
		ans = getMax(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}