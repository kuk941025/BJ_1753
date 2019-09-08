#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <limits.h>
#include <functional>
#include <stdio.h>

using namespace std;
struct info {
	int x, y, step, mode;
};
char g[510][510];
int vis[510][510], visT[510][510];
int dir[4][2] = { { 1,0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
int main() {
	int N, trans, ty, tx;
	cin >> N >> trans >> ty >> tx;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) { cin >> g[i][j]; vis[i][j] = visT[i][j] = INT_MAX; }

	info start; start.x = start.y = 1; start.step = start.mode = 0;
	queue <info> q;
	priority_queue <int, vector <int>, greater<int>> ans;
	vis[1][1] = 0;
	q.push(start); ans.push(INT_MAX);
	while (!q.empty()) {
		info out = q.front(); q.pop();
		//printf("%d %d %d == %d\n", out.y, out.x, out.mode, out.step);
		if (ty == out.y && tx == out.x) {
			ans.push(out.step); continue;
		}
		if (out.step >= ans.top()) continue;

		if (out.mode == 0) {
			info t = out; t.mode = 1; t.step = out.step + trans;
			if (visT[out.y][out.x] > out.step) { visT[out.y][out.x] = out.step + trans;  q.push(t); }
			for (int i = 0; i < 4; i++) {
				int next_y = out.y + dir[i][0]; int next_x = out.x + dir[i][1];
				if (g[next_y][next_x] != '\0' && vis[next_y][next_x] > out.step + 1) {
					info in;
					vis[next_y][next_x] = out.step + 1;
					in.x = next_x; in.y = next_y; in.step = out.step + 1; in.mode = 0;
					q.push(in);
				}
			}
		}
		else {
			info t = out; t.mode = 0;
			if (vis[out.y][out.x] > out.step) { vis[out.y][out.x] = out.step; q.push(t); }

			for (int i = 0; i < 4; i++) {
				int next_y = out.y + dir[i][0]; int next_x = out.x + dir[i][1];
				for (; next_y > 0 && next_y <= N && next_x > 0 && next_x <= N; next_y += dir[i][0], next_x += dir[i][1]) {
					if (g[next_y][next_x] == '#') {
						if (visT[next_y][next_x] > out.step + 1) {
							info in;
							visT[next_y][next_x] = out.step + 1;
							in.x = next_x; in.y = next_y; in.step = out.step + 1; in.mode = 1;
							q.push(in);
						}
						break;
					}
				}
			}
		}
	}
	cout << ans.top();
	return 0;
}