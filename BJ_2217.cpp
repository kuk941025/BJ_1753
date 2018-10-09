#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> v;
inline int getMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i] * (i + 1));
	}
	cout << ans;
	return 0;
}