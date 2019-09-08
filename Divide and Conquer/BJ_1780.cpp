#include <iostream>

using namespace std;
int in[3000][3000];
int cnt[3] = { 0 };
void solve(int x, int y, int len) {
	int start = in[y][x];
	bool flag = false;
	if (len == 1) {
		cnt[start + 1]++;
		return;
	}
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if (in[i][j] != start) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) cnt[start + 1]++;
	else {
		int gap = len / 3;
		for (int i = y; i < len + y; i += gap) {
			for (int j = x; j < len + x; j += gap) {
				solve(j, i, gap);
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> in[i][j];
	}

	solve(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << "\n";
	return 0;
}