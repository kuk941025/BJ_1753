#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int vis[10010];
vector <vector<int>> graph;
vector <int> ans;
int main() {
	int n, m;
	cin >> n >> m;
	graph.resize(n + 2);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	int cnt, max_cnt;
	max_cnt = 0;
	for (int i = 1; i <= n; i++) {
		queue <int> q;
		q.push(i);
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		while (!q.empty()) {
			int node = q.front(); q.pop();
			cnt++;
			for (int t : graph[node]) {
				if (vis[t] != 1) {
					q.push(t);
					vis[t] = 1;
				}
			}
		}
		if (cnt > max_cnt) max_cnt = cnt;

		ans.push_back(cnt);
	}

	int ans_size = ans.size();
	for (int i = 0; i < ans_size; i++) {
		if (ans[i] == max_cnt) cout << i + 1 << " ";
	}
	return 0;

}