#include <iostream>
#include <string.h>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
int arr[310][30], dp[310][30], tr[310][30], a[310];
int n, m;
void backtrack(int y, int x) {
	if (tr[y][x] == -1) { backtrack(y, x - 1); return; }
	if (tr[y][x] == 0) {
		int max = 0, maxIdx = 0;
		for (int i = 0; i <= x; i++) {
			if (arr[y][i] > max) { max = arr[y][i]; maxIdx = i; }
		}
		a[maxIdx] = y;
		return;
	}
	a[x] = y - tr[y][x];
	backtrack(tr[y][x], x - 1);
}
int main() {
	
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++){	
		int c; cin >> c;
		for (int j = 1; j <= m; j++) {
			cin >> arr[c][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tr[i][j] = 0;
			dp[i][j] = arr[i][j];
			if (arr[i][j] < dp[i][j - 1]) {
				dp[i][j] = dp[i][j - 1];
				tr[i][j] = -1;
			}
			for (int k = 1; k < i; k++) {
				if (dp[k][j - 1] + arr[i - k][j] >= dp[i][j]) {
					dp[i][j] = dp[k][j - 1] + arr[i - k][j];
					tr[i][j] = k;
				}
			}
		}
	}
	cout << dp[n][m] << "\n";
	backtrack(n, m);
	for (int i = 1; i <= m; i++)
		cout << a[i] << " ";

	return 0;
}