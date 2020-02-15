#include <iostream>

using namespace std;
int visited[10] = { 0 }, arr[10];
int N, K, ans = 0;

void dfs(int rem, int size) {
	if (rem < 500) return;
	if (size == N) {
		ans++; return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(rem + arr[i] - K, size + 1);
			visited[i] = 0;
		}
	}
	
}
int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> arr[i];
	dfs(500, 0);
	cout << ans << "\n";
	return 0;
}