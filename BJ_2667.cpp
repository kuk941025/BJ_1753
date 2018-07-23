#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char g[30][30];
int visited[30][30] = { 0 };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector <int> ans;


int dfs(int y, int x) {
	int cnt = 1;
	visited[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0]; int next_x = x + dir[i][1];
		if (g[next_y][next_x] == '1' && visited[next_y][next_x] == 0) {
			cnt += dfs(next_y, next_x);
		}
	}
	return cnt;
}
int main() {
	int N, cnt = 1;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> g[i][j];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (g[i][j] == '1' && visited[i][j] == 0) {
				ans.push_back(dfs(i, j));
			}
	}
	sort(ans.begin(), ans.end());
	int len = ans.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) printf("%d\n", ans[i]);
	return 0;
}