#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
long long in[100010], tree[400010];
long long init(long long  node, long long  s, long long  e){
	if (s == e) return tree[node] = in[s];
	else return tree[node] = init(node * 2, s, (s + e) / 2) + init(node * 2 + 1, (s + e) / 2 + 1, e);
}
long long sum(long long node, long long s, long long e, long long l, long long r) {
	if (l > e || s > r) return 0;
	if (l <= s && e <= r) return tree[node];
	return sum(node * 2, s, (s + e) / 2, l, r) + sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void update(long long node, long long  s, long long  e, long long  idx, long long diff) {
	if (idx < s || idx > e) return;
	tree[node] += diff;
	if (s < e) {
		update(node * 2, s, (s + e) / 2, idx, diff);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
	}
}
int main() {
	long long  n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		scanf("%lld", &in[i]);

	init(1, 0, n - 1);

	for (int i = 0; i < q; i++) {
		long long x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);

		if (x > y) {
			int temp; temp = x; x = y; y = temp;
		}
		printf("%lld\n", sum(1, 0, n - 1, x - 1, y - 1));

		a--;
		update(1, 0, n - 1, a, b - in[a]);
		in[a] = b;	
	}
	return 0;
}