#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long tree[4000010], in[1000010];
long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = in[start];
	else
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx > end || idx < start) return;
	tree[node] += diff;
	if (start < end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) cin >> in[i];

	init(1, 1, n);
	
	for (int i = 1; i <= m + k; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c - in[b]);
			in[b] = c;
		}
		else {
			cout << sum(1, 1, n, b, c) << "\n";
		}
	}

	return 0;
} 