#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
struct info {
	int color, size, id;
}in[200010];

bool cmp(const info a, const info b) { return a.size < b.size; }
int sum[200010] = { 0 };
int total = 0;
int ans[200010] = { 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> in[i].color >> in[i].size;
		in[i].id = i;
	}
	sort(in + 1, in + N + 1, cmp);
	for (int i = 1, j = 1; i <= N; i++) {
		for (; in[j].size < in[i].size; j++) { total += in[j].size; sum[in[j].color] += in[j].size;  }
		ans[in[i].id] = total - sum[in[i].color];
	}

	for (int i = 1; i <= N; i++) cout << ans[i] << "\n";
	return 0;
}