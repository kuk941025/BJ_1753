#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int arr[1010][1010], visited[1010][1010];
int n, m, k;
int dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

int ans = 0;
int bfs(int mid) {
	queue <pair<int, int>> q;

	if (mid == 0) return -1;
	memset(visited, 0, sizeof(visited));
	int minval = mid;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] <= minval) {
					q.push(make_pair(i, j));
					visited[i][j] = 1;
				}
			}
		}
		else {
			if (arr[i][1] <= minval) {
				q.push(make_pair(i, 1));
				visited[i][1] = 1;
			}
			if (arr[i][m] <= minval) {
				q.push(make_pair(i, m));
				visited[i][m] = 1;
			}
		}
	}

	int cnt = 0;
	while (!q.empty() && cnt < k) {
		int x, y;
		x = q.front().second; y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = y + dir[i][0]; int next_x = x + dir[i][1];
			if (arr[next_y][next_x] != -1 && visited[next_y][next_x] == 0 && arr[next_y][next_x] <= minval) {
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = 1;
			}
		}
		cnt++;
	}
	
	return cnt;

}
int main() {

	cin >> n >> m >> k;

	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];


	int left, right;
	left = 0; right = 1000000;
	while (left < right) {
		int mid = (left + right) / 2;
		if (bfs(mid) >= k) right = ans = mid;
		else left = mid + 1;
	}
	cout << ans << "\n";
	return 0;
}