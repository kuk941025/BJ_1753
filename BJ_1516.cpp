#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ind[510], cost[510], updated[510];
vector<vector<int>> v;
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		while (1)
		{
			int c; cin >> c;
			if (c == -1) break;
			else { v[c].push_back(i); ind[i]++; }
		}
	}

	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			updated[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int out = q.front(); q.pop();
		int size = v[out].size();
		for (int i = 0; i < size; i++) {
			int vertex = v[out][i];
			updated[vertex] = max(updated[vertex], updated[out] + cost[vertex]);
			if (--ind[vertex] == 0) {	
				q.push(vertex);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << updated[i] << "\n";
	return 0;
}