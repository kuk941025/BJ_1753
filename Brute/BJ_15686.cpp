#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

inline int getMin(int a, int b) { return a > b ? b : a; }
inline int getMax(int a, int b) { return a > b ? a : b; }
int N, M, ans = 1e9;
vector <pair<int, int>> h, c, s;
int map[55][18];

int getPoint(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int depth) {
	if (depth >= M) {
		int sum = 0;

		for (int i = 0; i < h.size(); i++) {
			int value = 1e9;
			for (int j = 0; j < s.size(); j++) {
				value = min(value, abs(h[i].first - s[j].first) + abs(h[i].second - s[j].second));

			}
			sum += value;
		}

		if (ans > sum)
			ans = sum;
		return;
	}


	for (int i = idx; i < c.size(); i++) {
		s.push_back(c[i]);
		dfs(i + 1, depth + 1);
		s.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) h.push_back(make_pair(j, i));
			else if (map[i][j] == 2) c.push_back(make_pair(j, i));
		}
	}

	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}