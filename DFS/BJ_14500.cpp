#include <iostream>
#include <string.h>
using namespace std;

inline int getMax(int a, int b) { return a > b ? a : b; }
int N, M, arr[510][510], visited[510][510];
int ans;
int dir[4][2] = { {1,0}, {-1,0}, {0, 1}, {0, -1} };
void solve(int depth, int cost, int x, int y) {
	if (depth == 3) {
		ans = getMax(cost, ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = dir[i][0] + x;
		int ny = dir[i][1] + y;

		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = 1;
		solve(depth + 1, cost + arr[ny][nx], nx, ny);
		visited[ny][nx] = 0;
	}
}

int shape1(int x, int y) {
	return arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
}
int shape2(int x, int y) {
	return arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
}
int shape3(int x, int y) {
	return arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
}
int shape4(int x, int y) {
	return arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			visited[i][j] = 1;
			solve(0, arr[i][j], j, i);
			visited[i][j] = 0;
			if (i + 2 < N && j + 1 < M) ans = getMax(ans, shape1(j, i));
			if (i + 2 < N && j - 1 >= 0) ans = getMax(ans, shape2(j, i));
			if (i + 1 < N && j + 2 < M) ans = getMax(ans, shape3(j, i));
			if (i - 1 >= 0 && j + 2 < M) ans = getMax(ans, shape4(j, i));
		}
	}

	cout << ans << "\n";
	return 0;
}