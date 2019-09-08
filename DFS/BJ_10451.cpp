#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <vector<int>> v;
int vis[1010];
void dfs(int node) {
	for (int out : v[node]) {
		if (vis[out] == 0) {
			vis[out] = 1;
			dfs(out);
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			int num; cin >> num;
			v[i].push_back(num);
		}
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				vis[i] = 1;
				dfs(i);
				cnt++;
			}
		}

		cout << cnt << "\n";
		int size = v.size();
		for (int i = 0; i < size; i++) {
			v[i].clear();
		}
		v.clear();
	}

	return 0;
}