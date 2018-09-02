#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
int ind[32010] = { 0 };
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		int size = v[i].size();
		for (int j = 0; j < size; j++) {
			ind[v[i][j]]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (ind[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int out = q.front(); q.pop();
		cout << out << " ";
		int size = v[out].size();
		for (int i = 0; i < size; i++) {
			
			if (--ind[v[out][i]] == 0) q.push(v[out][i]);
		}
	}
	return 0;
}