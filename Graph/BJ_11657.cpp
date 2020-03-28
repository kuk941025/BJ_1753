#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Edge {
public:
	int v, w;
	Edge(int v, int w) {
		this->v = v;
		this->w = w;
	}
};
int N, M;
int dist[550];
vector<Edge> v[550];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool cycle = false;
	cin >> N >> M;
	fill(dist + 1, dist + N + 1, INT_MAX);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(Edge(b, c));
	}

	dist[1] = 0;
	bool isUpdated = false;
	for (int i = 1; i <= N; i++) {
		isUpdated = false;
		for (int j = 1; j <= N; j++) {
			for (Edge out : v[j]) {
				if (dist[j] != INT_MAX && dist[out.v] > out.w + dist[j]) {
					dist[out.v] = out.w + dist[j];

					isUpdated = true;
					if (i == N) cycle = true;
				}
			}
		}
		if (!isUpdated) break;
	}

	if (cycle) cout << "-1" << "\n";
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INT_MAX) cout << "-1" << "\n";
			else cout << dist[i] << "\n";
		}
	}
	return 0;
}