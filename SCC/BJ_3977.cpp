#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> g[100010], rg[100010];
int vis[100010], freq[100010], time, sccCnt;
int scc[100010];
void dfs(int vt) {
	vis[vt] = 1;
	int len = g[vt].size();
	for (int i = 0; i < len; i++) {
		if (!vis[g[vt][i]])
			dfs(g[vt][i]);
	}

	freq[time++] = vt;
}
void rdfs(int vt, int num) {

	int len = rg[vt].size();

	vis[vt] = num;
	for (int i = 0; i < len; i++) {
		if (!vis[rg[vt][i]]) rdfs(rg[vt][i], num);
	}

}
int main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			a++; b++;
			g[a].push_back(b);
			rg[b].push_back(a);
		}

		time = 1;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) dfs(i);


		memset(vis, 0, sizeof(vis));
		sccCnt = 0;
		for (int i = time - 1; i > 0; i--) {
			if (!vis[freq[i]]) {
				rdfs(freq[i], ++sccCnt);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int ver : rg[i]) {
				if (vis[i] != vis[ver]) scc[vis[i]]++;
			}
		}
		int cnt = 0;
		vector <int> ans;
		for (int i = 1; i <= sccCnt; i++) {
			if (scc[i] == 0) {
				cnt++;
			}
		}

		if (cnt == 1) {
			vector <int> ans;
			for (int i = 1; i <= sccCnt; i++) {
				if (scc[i] == 0) {
					for (int j = 1; j <= n; j++) {
						if (vis[j] == i) ans.push_back(j);
					}
				}
				break;
			}
			sort(ans.begin(), ans.end());
			int size = ans.size();
			for (int i = 0; i < size; i++)
				cout << ans[i] - 1 << "\n";
		}
		else cout << "Confused" << "\n";
		cout << "\n";
		memset(vis, 0, sizeof(vis));
		memset(scc, 0, sizeof(scc));
		memset(freq, 0, sizeof(freq));
		for (int i = 1; i <= n; i++) {
			g[i].clear(); rg[i].clear();
		}

	}
	return 0;
}
