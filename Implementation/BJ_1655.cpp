#include <iostream>
#include <functional>
#include <queue>

using namespace std;
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int num;
	while (N--) {
		cin >> num;
		if (maxH.size() == minH.size()) maxH.push(num);
		else minH.push(num);

		if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top()) {
			int a, b;
			a = maxH.top(); b = minH.top();
			maxH.push(b); minH.push(a);
			maxH.pop(); minH.pop();
		}

		cout << maxH.top() << "\n";
	}

	return 0;
}