#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;
char arr[1010][1010] = { 0 };
int visited[1010][1010] = { 0 }, visitedWall[1010][1010] = { 0 };
int N, M;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int ans = INT_MAX;
inline int getMin(int a, int b) { return a > b ? b : a; };

struct coord {
	int x, y, wall, cnt;
};
queue<coord> q;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}

	visited[1][1] = 1;
	q.push(coord{ 1, 1, 0, 1 });
	while (!q.empty()) {
		coord out = q.front(); q.pop();
		if (out.y == N && out.x == M) {
			ans = getMin(out.cnt, ans);
		}

		for (int i = 0; i < 4; i++) {
			int ny = out.y + dir[i][0]; int nx = out.x + dir[i][1];
	
			if (out.wall == 0) {
				if (visited[ny][nx] == 0 && arr[ny][nx] == '0') {
					visited[ny][nx] = 1;
					q.push(coord{ nx, ny, 0, out.cnt + 1 });
				}
				else if (visitedWall[ny][nx] == 0 && arr[ny][nx] == '1') {
					visitedWall[ny][nx] = 1;
					q.push(coord{ nx, ny, 1, out.cnt + 1 });
				}
			}
			else {
				if (visitedWall[ny][nx] == 0 && arr[ny][nx] == '0') {
					visitedWall[ny][nx] = 1;
					q.push(coord{ nx, ny, 1, out.cnt + 1 });
				}
			}
		}
	}

	if (ans == INT_MAX) {
		cout << "-1" << "\n";
	}
	else cout << ans << "\n";
	return 0;
}