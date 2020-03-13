#include <iostream>
#include <unordered_set>
using namespace std;

int a, b, cnt = 1;
unordered_set<int> set;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int cnt, nodeCnt;
	nodeCnt = 0;
	cnt = 1;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) return 0;
		if (a == 0 && b == 0) {
			if (set.size() == 0 || set.size() == nodeCnt + 1) {
				cout << "Case " << cnt << " is a tree.\n";
			}
			else cout << "Case " << cnt << " is not a tree.\n";
			cnt++;
			nodeCnt = 0;
			set.clear();
		}
		else {
			set.insert(a);
			set.insert(b);
			nodeCnt++;
		}
	}

	return 0;
}