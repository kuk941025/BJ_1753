#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
int visited[11] = { 0 };
long long ansMax = LLONG_MIN, ansMin = LLONG_MAX;
char op[11];
int K;
vector<int> ans;
inline long long getMax(long long a, long long b) { return a > b ? a : b; }
inline long long getMin(long long a, long long b) { return a > b ? b : a; }
void solve(int idx) {
	if (idx >= K) {
		long long num = 0;
		for (int i = 0; i < ans.size(); i++) {
			num *= 10;
			num += ans[i];

		}

   		ansMax = getMax(ansMax, num);
		ansMin = getMin(ansMin, num);

		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i] == 0) {
			if (op[idx] == '>' && i < ans[idx]) {
				ans.push_back(i);
				visited[i] = 1;
				solve(idx + 1);
				visited[i] = 0;
				ans.pop_back();

			}
			else if (op[idx] == '<' && i > ans[idx]) {
				ans.push_back(i);
				visited[i] = 1;
				solve(idx + 1);
				visited[i] = 0;
				ans.pop_back();
			}
		}
	}
}
int main() {
	cin >> K;
	for (int i = 0; i < K; i++) cin >> op[i];

	for (int i = 0; i < 10; i++) {
		visited[i] = 1;
		ans.push_back(i);
		solve(0);
		ans.pop_back();
		visited[i] = 0;
	}
	cout << ansMax << "\n";
	cout.width(K + 1);
	cout.fill('0');
	cout << ansMin << "\n";
	return 0;
}