#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct edge {
	int v, w;
	edge() {}
	edge(int v, int w) : v(v), w(w) {}
	bool operator < (edge A) const { return w > A.w; }
};
const int v_max = 20010;
int dist[20010], visited[20010] = { 0 };
vector <edge> g[v_max];
int main() {
	int v, e, s;
	cin >> v >> e >> s;
	for (int i = 1; i <= v; i++) dist[i] = INF;
	for (int i = 1; i <= e; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back(edge(y, w));
	}

	priority_queue<edge> pq;
	dist[s] = 0;
	pq.push(edge(s, 0));

	while (!pq.empty()) {
		edge out = pq.top(); pq.pop();
		visited[out.v] = 1;
		for (edge now : g[out.v]) {
			if (visited[now.v] == 0 && dist[now.v] > out.w + now.w) {
				pq.push(edge(now.v, out.w + now.w));
				dist[now.v] = out.w + now.w;
			}
		}
	}
	for (int i = 1; i <= v; i++) dist[i] == INF ? printf("INF\n") : printf("%d\n", dist[i]);
}