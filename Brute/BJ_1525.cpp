#include <iostream>
#include <string>
#include <limits.h>
#include <set>
#include <queue>

using namespace std;
inline int getMin(int a, int b) { return a > b ? b : a; }
string last = "123456780";
int ans = INT_MAX;

struct unit {
	string in;
	int cnt;
};

queue<unit> q;
set<string> s;

int dir[] = { -1, 1, 3, -3 };
int main() {
	string in = "";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			char a; cin >> a;
			in.push_back(a);
		}
	}

	s.insert(in);
	q.push({ in ,0 });
	while (!q.empty()) {
		unit out = q.front(); q.pop();
		if (out.cnt > ans) continue;
		if (out.in.compare(last) == 0) {
			ans = getMin(ans, out.cnt);
			continue;
		}

		//try all possible combo if not visited
		//find empty
		int curIdx = out.in.find('0');
		
		if (curIdx == 0 || curIdx == 3 || curIdx == 6) {
			//no left
			for (int i = 0; i < 4; i++) {
				if (dir[i] == -1) continue;
				int nextIdx = curIdx + dir[i];
				if (nextIdx >= 0 && nextIdx < 9) {
					string temp = out.in;
					swap(temp[nextIdx], temp[curIdx]);
					if (s.find(temp) == s.end()) {
						q.push({ temp, out.cnt + 1 });
						s.insert(temp);
					}
				}
			}
		}
		else if (curIdx == 2 || curIdx == 5 || curIdx == 8) {
			//no right
			for (int i = 0; i < 4; i++) {
				if (dir[i] == 1) continue;
				int nextIdx = curIdx + dir[i];
				if (nextIdx >= 0 && nextIdx < 9) {
					string temp = out.in;
					swap(temp[nextIdx], temp[curIdx]);
					if (s.find(temp) == s.end()) {
						q.push({ temp, out.cnt + 1 });
						s.insert(temp);
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nextIdx = curIdx + dir[i];
				if (nextIdx >= 0 && nextIdx < 9) {
					string temp = out.in;
					swap(temp[nextIdx], temp[curIdx]);
					if (s.find(temp) == s.end()) {
						q.push({ temp, out.cnt + 1 });
						s.insert(temp);
					}
				}
			}
		}


	}

	if (ans == INT_MAX) cout << "-1" << endl;
	else cout << ans << endl;
	return 0;
}