#include <iostream>

using namespace std;
int N, ans = 0; 
int arr[15] = { 0 }, d1[50] = { 0 }, d2[50] = { 0 };
void solve(int col) {
	if (col == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] == 1) continue;
		if (d1[col + i] || d2[N - 1 + (col - i)]) continue;

		arr[i] = d1[col + i] = d2[N - 1 + (col - i)] = 1;
		solve(col + 1);
		arr[i] = d1[col + i] = d2[N - 1 + (col - i)] = 0;
	}
}
int main() {
	cin >> N;

	solve(0);
	cout << ans << endl;
	return 0;
}