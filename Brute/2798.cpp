#include <iostream>
#include <vector>
using namespace std;

vector<int> visits;
int arr[110], res = -1;
int N, M;
void dfs(int sum, int depth) {
	if (depth == 0) {
		if (sum > res) res = sum;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		bool used_flag = false;
		for (auto visit : visits) {
			if (visit == i) used_flag = true;
		}

		if (used_flag) continue;
		//if idx is not used

		if (sum + arr[i] <= M) {
			visits.push_back(i);
			dfs(sum + arr[i], depth - 1);
			visits.pop_back();
		}
	}

}
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 3);
	cout << res;

	return 0;
}