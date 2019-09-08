#include <iostream>

using namespace std;

int p[210], level[210];

int find(int x) {
	if (p[x] == x) return x;
	p[x] = find(p[x]);
	return p[x];
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (level[x] > level[y]) {
		int temp = x;
		x = y;
		y = temp;
	}

	p[x] = y;
	if (level[x] == level[y]) level[x]++;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		level[i] = 0;
		for (int j = 1; j <= n; j++) {
			int num; cin >> num;
			if (num) {
				uni(i, num);
			}
		}
	}

	int cnt = 0;
	int num; cin >> num;
	int base = find(num);
	
	for (int i = 1; i < m; i++) {
		cin >> num;
		if (base != find(num)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}