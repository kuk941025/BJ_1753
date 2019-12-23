#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

int arr[60][60] = { 0 }, visited[60][60] = { 0 };
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

int main() {
	
	while (1) {
		queue<pair<int, int>> q;
		int cnt = 0;
		int w, h;
		cin >> w >> h;
	
		if (w == 0 && h == 0) break;


		memset(arr, -1, sizeof arr);
		memset(visited, 0, sizeof visited);
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (arr[i][j] == 1 && visited[i][j] == 0) {
					q.push(make_pair(j, i));
					cnt++;

					while (!q.empty()) {
						pair<int, int> next = q.front(); q.pop();
					
						for (int k = 0; k < 8; k++) {
							int next_y = dir[k][0] + next.second; int next_x = dir[k][1] + next.first;

							if (arr[next_y][next_x] == 1 && visited[next_y][next_x] == 0) {
								visited[next_y][next_x] = 1;
								q.push(make_pair(next_x, next_y));
							}
						}
					}
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}