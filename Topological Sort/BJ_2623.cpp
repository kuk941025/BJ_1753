#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> graph[1010];
vector<int> ans;
queue<int> q;
int N, M, ind[1010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int num, start; cin >> num >> start;
		for (int j = 0; j < num - 1; j++) {
			int a; cin >> a;
			graph[start].push_back(a);
			ind[a]++;
			start = a;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) q.push(i);
	}


	while (!q.empty()) {
		int out = q.front(); q.pop();
		ans.push_back(out);
		for (auto next : graph[out]) {
			if (--ind[next] == 0) {
				q.push(next);
			}
		}
	}

	if (ans.size() == N) {
		for (auto out : ans) {
			cout << out << "\n";
		}
	}
	else cout << "0\n";
	return 0;
}