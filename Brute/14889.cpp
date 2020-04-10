#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;
int N, arr[30][30], visited[30], ans = INT_MAX;
vector<int> v1, v2;
void solve(int idx) {
	if (idx >= N + 1) {
		if (v1.size() == N / 2 && v2.size() == N / 2) {
			int start, link;
			start = link = 0;
			for (int i = 0; i < N / 2; i++) {
				for (int j = i + 1; j < N / 2; j++) {
					start += arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]];
					link += arr[v2[i]][v2[j]] + arr[v2[j]][v2[i]];
				}
			}

			ans = min(ans, abs(start - link));
		}
		return;
	}


	v1.push_back(idx);
	solve(idx + 1);
	v1.pop_back();

	v2.push_back(idx);
	solve(idx + 1);
	v2.pop_back();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	solve(1);
	cout << ans << "\n";
	return 0;
}