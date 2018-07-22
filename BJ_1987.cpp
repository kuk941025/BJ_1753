#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;
char g[30][30];
int visited[30] = { 0 };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1 } };
int m = 0;

void dfs(int y, int x, int cnt) {
	if (cnt > m) m = cnt;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0];
		int next_x = x + dir[i][1];
		if (g[next_y][next_x] != '\0' && visited[g[next_y][next_x] - 'A'] == 0) {
			visited[g[next_y][next_x] - 'A'] = 1;
			dfs(next_y, next_x, cnt + 1);
			visited[g[next_y][next_x] - 'A'] = 0;
		}
	}
}
int main() {
	int r, c;
	string in;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		cin >> in;
		int len = in.length();
		for (int j = 1; j <= len; j++) {
			g[i][j] = in[j - 1];
		}
	}
	visited[g[1][1] - 'A'] = 1;
	dfs(1, 1, 1);
	cout << m << "\n";
	
	return 0;
}