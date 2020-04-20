#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
class Edge {
public:
	int node, dist;
	Edge(int node, int dist) {
		this->node = node;
		this->dist = dist;
	}

	bool operator < (Edge b) const{
		return this->dist > b.dist;
	}
};

vector<Edge> g[20010];
priority_queue<Edge> pq;
int visited[20010], dist[20010], N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(Edge(b, 1));
		g[b].push_back(Edge(a, 1));

	}
	pq.push(Edge(1, 0));
	dist[1] = 0;


	while (!pq.empty()) {
		Edge cur = pq.top(); pq.pop();
		visited[cur.node] = 1;

		for (auto out : g[cur.node]) {
			if (visited[out.node] == 0 && dist[out.node] > out.dist + cur.dist) {
				dist[out.node] = out.dist + cur.dist;
				
				pq.push(Edge(out.node, out.dist + cur.dist));
			}

		}
	}


	int max, maxIdx, cnt = 0;
	max = INT_MIN;
	for (int i = 1; i <= N; i++) {
		if (dist[i] > max) {
			max = dist[i];
			maxIdx = i;
			cnt = 1;
		}
		else if (dist[i] == max) cnt++;
	}

	cout << maxIdx << " " << max << " " << cnt << "\n";
	return 0;
}