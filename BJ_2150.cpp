#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
vector <int> v[10010], rv[10010];
vector <vector<int>> sol;
int vis[10010], freq[10010], time;

void dfs(int vt) {
	vis[vt] = 1;
	int len = v[vt].size();
	for (int i = 0; i < len; i++) {
		if (!vis[v[vt][i]])
			dfs(v[vt][i]);
	}

	freq[time++] = vt;
}

void rdfs(int vt, vector<int> &s) {
	vis[vt] = 1;
	int len = rv[vt].size();
	s.push_back(vt);
	for (int i = 0; i < len; i++) {
		if (!vis[rv[vt][i]]) rdfs(rv[vt][i], s);
	}

}
int main() {
	int k, e;
	cin >> k >> e;

	
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		rv[b].push_back(a);
	}

	time = 1;
	for (int i = 1; i <= k; i++) {
		if (!vis[i]) dfs(i);
	}

	memset(vis, 0, sizeof(vis));
	time--;
	for (int i = time; i >= 1; i--) {
		int vt = freq[i];
		if (!vis[vt]) {
			vector <int> s;
			rdfs(vt, s);
			sort(s.begin(), s.end());
			sol.push_back(s);
		}
	}
	int size = sol.size();
	cout << size << "\n";
	sort(sol.begin(), sol.end());
	for (int i = 0; i < size; i++) {
		int subSize = sol[i].size();
		for (int j = 0; j < subSize; j++)
			cout << sol[i][j] << " ";
		cout << "-1\n";
	}
	return 0;
}