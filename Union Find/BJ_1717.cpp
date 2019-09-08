#include <iostream>
#include <stdio.h>
int p[1000010] = { 0 };
int level[1000010] = { 0 };

using namespace std;
int find(int x) {
	if (p[x] == x) return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
}
int main() {
	int n, m;
	cin >> n >> m;

	//init
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		level[i] = 0;
	}

	while (m--) {
		int in, x, y;
		
		scanf("%d %d %d", &in, &x, &y);
		//cin >> in >> x >> y;
		if (in) {
			if (find(x) == find(y)) printf("YES\n");
			else printf("NO\n");
		}
		else {
			merge(x, y);
		}
	}

	return 0;
}