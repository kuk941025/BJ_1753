#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int N, arr[30][30], visited[30][30];
int ans = 0;
struct coord {
	int x, y, cnt;
};
vector<coord> fish;

void bfs(int sx, int sy, int size) {
	queue<coord> q;
	
	memset(visited, 0, sizeof visited);
	q.push({ sx, sy, 0 });
	int minCnt = INT_MAX;

	while (!q.empty()) {
		coord out = q.front(); q.pop();
		if (out.cnt > minCnt) continue;
		
		//check if nearest one is found
		if (arr[out.y][out.x] > 0 && arr[out.y][out.x] < size && arr[out.y][out.x] != 9) {
			minCnt = out.cnt;
			fish.push_back(out);
		}

		for (int i = 0; i < 4; i++) {
			int nx = out.x + dir[i][0], ny = out.y + dir[i][1];
			if (visited[ny][nx] == 0 && arr[ny][nx] >= 0 && arr[ny][nx] <= size && arr[ny][nx] != 9) {
				visited[ny][nx] = 1;
				q.push({ nx, ny, out.cnt + 1 });
			}
		}
	}
}
bool compare(coord a, coord b) {
	if (a.cnt == b.cnt) {
		if (a.y == b.y) return a.x < b.x;
		else return a.y < b.y;
	}
	else return a.cnt < b.cnt;
}
void solve(int size, int eaten) {
	if (eaten == size) {
		size++; eaten = 0;
	}

	//locate shark
	int cx, cy;
	cx = cy = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cx >= 0) continue;
			if (arr[i][j] == 9) {
				cx = j, cy = i;
				break;
			}
		}
	}

	//find fish
	fish.clear();
	bfs(cx, cy, size);

	int found = fish.size();
	if (found == 0) return;
	else {
		//sort
		sort(fish.begin(), fish.end(), compare);
		arr[fish[0].y][fish[0].x] = 9;
		arr[cy][cx] = 0;
		ans += fish[0].cnt;
		solve(size, eaten + 1);
	}
}
int main() {
	cin >> N;
	
	memset(arr, -1, sizeof arr);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}

	solve(2, 0);
	cout << ans << "\n";
	return 0;
}