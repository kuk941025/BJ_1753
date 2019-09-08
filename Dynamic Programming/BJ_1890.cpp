#include <iostream>
#include <string.h>
using namespace std;

long long arr[110][110] = { -1 };
long long dp[110][110] = { 0 }, dir[][2] = { {1, 0}, {0, 1} };
int n;
long long dfs(int y, int x) {
	long long res = 0;
	if (y == n && x == n) return 1;
	if (arr[y][x] == 0 ||  arr[y][x] == -1) return 0;
	
	if (dp[y][x] != 0) return dp[y][x];
	else {
		for (int i = 0; i < 2; i++) {
			res += dfs(y + dir[i][0] * arr[y][x], x + dir[i][1] * arr[y][x]);
		}
		dp[y][x] = res;
	}

	return res;
}
int main() {

	cin >> n;
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}

	dfs(1, 1);

	cout << dp[1][1] << "\n";
	return 0;
}