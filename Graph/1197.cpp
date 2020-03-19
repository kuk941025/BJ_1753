#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int p[100010] = { 0 };
int V, E;

class Edge {
public:
	int node[2];
	int dist;
	Edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}

	bool operator < (Edge& e) {
		return this->dist < e.dist;
	}
};
vector<Edge> v;

int find(int x) {
	if (p[x] == x) return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> V >> E;

	for (int i = 1; i <= V; i++) p[i] = i;
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;	
		v.push_back(Edge(a, b, c));
	}
	
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i].node[0]) != find(v[i].node[1])) {
			sum += v[i].dist;
			merge(v[i].node[0], v[i].node[1]);
		}
	}

	cout << sum << "\n";
	return 0;
}