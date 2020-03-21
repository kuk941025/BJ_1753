#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Edge {
public: 
	int node[2], distance;
	Edge(int a, int b, int c) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = c;
	}
	bool operator < (Edge& a) {
		return this->distance < a.distance;
	}
};
vector<Edge> v;
int N, M, p[1010];

int find(int a) {
	if (p[a] == a) return a;
	p[a] = find(p[a]);
	return p[a];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) p[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) p[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}

	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (find(v[i].node[0]) != find(v[i].node[1])) {
			ans += v[i].distance;
			merge(v[i].node[0], v[i].node[1]);
		}
	}

	cout << ans << "\n";
	return 0;
}