#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;
vector <vector<int>> g;
int indgree[32010];
int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n + 2);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		indgree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indgree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int out = pq.top(); pq.pop();
		cout << out << " ";
		for (int v : g[out]) {
			indgree[v]--;
			if (indgree[v] == 0) pq.push(v);
		}
	}

	return 0;
}