#include <iostream>
#include <string.h>
using namespace std;
int N, arr[110][110] = { 0 }, max_height;
int max_area = 0;
int visited[110][110];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, { 0, 1} };

void dfs(int x, int y, int height) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0]; int next_x = x + dir[i][1];
		
		if (arr[next_y][next_x] > height && visited[next_y][next_x] == 0) {
			dfs(next_x, next_y, height);
		}
	}
}

void count(int x, int y) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0]; int next_x = x + dir[i][1];

		if (visited[next_y][next_x] == 1) {
			count(next_x, next_y);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max_height) max_height = arr[i][j];
		}
	}


	for (int n = 0; n <= max_height; n++) {
		memset(visited, 0, sizeof visited);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > n && visited[i][j] == 0)
					dfs(j, i, n);

			}
		}

		//count number
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j] == 1) {
					cnt++;
					count(j, i);
				}
			}
		}

		if (cnt > max_area) max_area = cnt;
	}

	cout << max_area;

	return 0;
}