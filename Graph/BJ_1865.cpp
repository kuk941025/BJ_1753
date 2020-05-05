#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>

class Edge {
public:
	int v, w;
	Edge(int v, int w) {
		this->v = v;
		this->w = w;
	}
};

using namespace std;
vector<Edge> g[510];
int dist[510], T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	
	while (T--) {
		int N, M, W;
		cin >> N >> M >> W;
		for (int i = 1; i < 510; i++) dist[i] = INT_MAX;
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back({ b, c });
			g[b].push_back({ a, c });
		}

		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back({ b, -c });
		}

		dist[1] = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto out : g[j]) {
					if (dist[j] != INT_MAX && dist[out.v] > out.w + dist[j]) {
						dist[out.v] = out.w + dist[j];

					 }
				}
			}

		}
		
		bool cycle = false;
		for (int i = 1; i <= N; i++) {
			for (auto out : g[i]) {
				if (dist[out.v] > dist[i] + out.w) {
					cycle = true;
				}
			}

			if (cycle) break;
		}
		if (cycle) cout << "YES\n";
		else cout << "NO\n";

		for (int i = 1; i <= N; i++) g[i].clear();
	}
	return 0;
}