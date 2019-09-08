#include <iostream>

using namespace std;

int arr[2510][2510];
int cnt = 0;
int dir[][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };

void dfs(int x, int y) {
	arr[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];

		if (next_y >= 0 && next_x >= 0 && arr[next_y][next_x] == 1) {
			dfs(next_x, next_y);
		}
	}
}
int main() {
	int T;
	int M, N, K;
	
	cin >> T;
	
	while (T--) {
		cin >> M >> N >> K;
		cnt = 0;
		while (K--) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;

		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					dfs(j, i);
				}
			}
		}

		cout << cnt << "\n";
	}


	return 0;
}