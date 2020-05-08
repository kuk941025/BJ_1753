#include <iostream>

using namespace std;
inline int getMax(int a, int b) { return a > b ? a : b; }
int N, arr[20][2], ans = 0;
void solve(int idx, int prev, int total) {
	if (idx > N) {
		if (idx - 1 == N) total += prev;
		ans = getMax(ans, total);
	}
	else total += prev;
	for (int i = idx; i <= N; i++) {
		solve(i + arr[i][0], arr[i][1], total);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}

	for (int i = 1; i <= N; i++) {
		solve(i, 0, 0);
	}

	cout << ans << "\n";
	return 0;
}