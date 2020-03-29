#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int V, E, dis[100010], cnt;
set<pair<int, int>> ans;
vector<int> v[100010];

int dfs(int cur, int parent) {
	dis[cur] = ++cnt;
	int ret = dis[cur];

	for (auto out : v[cur]) {
		if (out == parent) continue;
		if (!dis[out]) {
			int res = dfs(out, cur);
			if (res > dis[cur])
				ans.insert(make_pair(min(cur, out), max(cur, out)));
			ret = min(ret, res);
		}
		else ret = min(ret, dis[out]);
	}

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
		if (!dis[i]) dfs(i, 0);
	}

	cout << ans.size() << "\n";
	for (auto out : ans) {
		cout << out.first << " " << out.second << "\n";
	}

	return 0;
}