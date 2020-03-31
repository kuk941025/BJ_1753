#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
class Edge {
public:
	int v, w;
	Edge(int v, int w) {
		this->v = v;
		this->w = w;
	}
	bool operator < (Edge a) const {
		return this->w > a.w;
	}
};

int N, M, visited[1010], dist[1010];
vector<Edge> v[1010];
priority_queue<Edge> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	fill(dist, dist + N + 1, INT_MAX);
	for (int i = 0; i < M; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		v[a].push_back(Edge(b, c));
	}

	int s, e;
	cin >> s >> e;

	dist[s] = 0;
	pq.push(Edge(s, 0));
	
	while (!pq.empty()) {
		Edge out = pq.top(); pq.pop();
		visited[out.v] = 1;

		for (Edge cur : v[out.v]) {
			if (visited[cur.v] == 0 && dist[cur.v] > cur.w + out.w) {
				dist[cur.v] = cur.w + out.w;
				pq.push(Edge(cur.v, cur.w + out.w));
			}
		}
	}

	cout << dist[e] << "\n";
	return 0;
}