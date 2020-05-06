#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
map<string, int> m;
vector<string> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	string in;
	for (int i = 0; i < N; i++) {
		cin >> in;
		m.insert(make_pair(in, 1));
	}

	for (int i = 0; i < M; i++) {
		cin >> in;
		if (m.count(in)) {
			ans.push_back(in);
		}
	}


	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";

	for (auto out : ans) {
		cout << out << "\n";
	}
	return 0;
}