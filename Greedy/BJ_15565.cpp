#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <limits.h>

using namespace std;
int in[1000010] = { 0 };
int main() {
	int N, k;
	cin >> N >> k;
	for (int i = 0; i < N; i++) cin >> in[i];

	int min = INT_MAX, st, en, cnt = 0;
	for (st = en = 0; st < N; st++) {
		while (cnt < k) {
			if (en >= N) break;
			if (in[en++] == 1) cnt++;
		}
		if (cnt == k && en - st < min) min = en - st;
		if (in[st] == 1) cnt--;
		if (cnt < k - 1) break;
	}
	if (min == INT_MAX) cout << "-1";
	else cout << min << "\n";
	return 0;
}