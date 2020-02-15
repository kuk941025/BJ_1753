#include <iostream>

using namespace std;
int N, M, dp[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		dp[i] = num + dp[i - 1];
	}

	while (M--) {
		int a, b; cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}

	return 0;
}