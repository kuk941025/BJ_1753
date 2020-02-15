#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, N;
vector <pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end());

		int cnt = 1, target = v[0].second;;
		
		for (int i = 1; i < N; i++) {
			if (v[i].second < target) {
				cnt++;
				target = v[i].second;
			}
		}
		cout << cnt << "\n";
		v.clear();
	}
	return 0;
}