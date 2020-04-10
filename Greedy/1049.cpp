#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int N, M, ans;
vector<int> v1, v2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v1.push_back(a); v2.push_back(b);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int rem = N % 6;
	if (rem == 0) ans = v1[0] * N / 6;
	else ans = v1[0] * (N / 6 + 1);

	
	ans = min(ans, v1[0] * (N / 6) + v2[0] * (N % 6));
	ans = min(ans, v2[0] * N);
	cout << ans << "\n";
	return 0;
}