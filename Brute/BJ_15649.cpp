#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int N, M;
vector<int> v;
int visited[10];

void dfs() {
	if (v.size() == M) {
		//print
		for (auto out : v) {
			cout << out << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			v.push_back(i);
			visited[i] = 1;
			dfs();
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int main() {
	cin >> N >> M;
	memset(visited, 0, sizeof(visited));
	dfs();

	return 0;
}