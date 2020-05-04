#include <iostream>
#include <queue>

struct item {
	int x, y, cnt;
};
using namespace std;
int arr[310][310], visited[310][310];
int N, M;
queue<item> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}

	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		auto out = q.front(); q.pop();
		if (out.y == N - 1&& out.x == M - 1) {
			cout << out.cnt << "\n";
			return 0;
		}


		int max_step = arr[out.y][out.x];
		
		//horizontal
		for (int i = 1; i <= max_step && out.x + i < M; i++) {
			int next_x = out.x + i;
			if (!visited[out.y][next_x]) {
				visited[out.y][next_x] = 1;
				q.push({ next_x, out.y, out.cnt + 1 });
			}

		}
		//vertical
		for (int i = 1; i <= max_step && out.y + i < N; i++) {
			int next_y = out.y + i;
			if (!visited[next_y][out.x]) {
				visited[next_y][out.x] = 1;
				q.push({ out.x, next_y, out.cnt + 1 });
			}

		}

		
	}
	return 0;
}