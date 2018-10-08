#include <iostream>
#include <vector>
using namespace std;
struct Circle {
	int x, y, r;
};
vector<Circle> g;
int parent[3010];
int lvl[3010];
int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (lvl[x] > lvl[y]) {
		int temp = x;
		x = y;
		y = temp;
	}
	parent[x] = y;
	if (lvl[x] == lvl[y]) lvl[y]++;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		int cnt;
		for (int i = 0; i < n; i++ ) {
			int a, b, c; cin >> a >> b >> c;
			Circle circle;
			circle.x = a; circle.y = b; circle.r = c;
			
			g.push_back(circle);
			parent[i] = i;
			lvl[i] = 0;
		}
		cnt = n;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int x = g[i].x - g[j].x;
				int y = g[i].y - g[j].y;
				int r = g[i].r + g[j].r;
				int d = x * x + y * y;
				if (r*r >= d) {
					//intersect
					if (find(i) != find(j)) {
						merge(i, j);
						cnt--;
					}
				}
			}
		}
		cout << cnt << "\n";
		g.clear();
	}

	return 0;
}