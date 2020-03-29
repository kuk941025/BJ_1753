#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int V, E, dist[10010], cnt;
vector<int> v[10010];
set<int> ans;
int dfs(int cur, bool root) {
	dist[cur] = ++cnt;
	int ret = dist[cur];
	int child = 0;

	for (int out : v[cur]) {
		if (!dist[out]) {
			child++;
			int low = dfs(out, false);
			if (!root && low >= dist[cur]) ans.insert(cur);
			ret = min(ret, low);
		}
		else {
			ret = min(ret, dist[out]);
		}
	}

	if (root && child > 1) ans.insert(cur);
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!dist[i]) dfs(i, true);
	}

	cout << ans.size() << "\n";
	for (auto out : ans) {
		cout << out << " ";
	}
	cout << "\n";
	return 0;
}