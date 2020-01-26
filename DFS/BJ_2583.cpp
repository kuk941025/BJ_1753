#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
int arr[110][110];
int M, N, K;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<int> v;

int dfs(int x, int y) {
	int sum = 0;
	arr[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (arr[ny][nx] == 0) {
			sum += dfs(nx, ny);
		}
	}

	return sum + 1;
}
int main() {
	cin >> M >> N >> K;
	memset(arr, -1, sizeof arr);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) arr[i][j] = 0;
	}
	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1 + 1; j <= y2; j++) {
			for (int k = x1 + 1; k <= x2; k++) {
				arr[j][k] = 1;
			}
		}
	}


	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0) {
				v.push_back(dfs(j, i));
			}
		}
	}
	cout << v.size() << "\n";
	//sort
	sort(v.begin(), v.end());
	for (auto ans : v) {
		cout << ans << " ";
	}
	return 0;
}