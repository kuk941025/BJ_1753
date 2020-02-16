#include <iostream>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.size() == 0) cout << "0\n";
			else {
				cout << pq.top() << "\n"; 
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}