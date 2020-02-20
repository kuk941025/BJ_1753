#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>

using namespace std;
map<int, int> a, b;

vector <int> pn;
int N, M;
int visited[35000] = { 0 };
int LIMIT = 1000000000;
inline int getMin(int a, int b) { return a > b ? b : a; }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < 35000; i++) {
		if (visited[i] == 1) continue;
		pn.push_back(i);
		
		for (int j = i + i; j < 35000; j += i) visited[j] = 1;
	}


	cin >> N;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		int temp = num;

		while (temp > 1) {
			num = temp;
			for (auto cur : pn) {
				if (temp % cur == 0) {
					a[cur]++;
					temp /= cur;
					break;
				}
			}
			if (temp == num) {
				a[temp]++;
				break;
			}
		}

	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		int temp = num;

		while (temp > 1) {
			num = temp;
			for (auto cur : pn) {
				if (temp % cur == 0) {
					b[cur]++;
					temp /= cur;
					break;
				}
			}
			if (temp == num) {
				b[temp]++;
				break;
			}
		}

	}

	map<int, int>::iterator iter;
	long long ans = 1;
	bool isOver = false;
	for (iter = b.begin(); iter != b.end(); iter++) {
		if (!a.count(iter->first)) continue;
		else {
			int po = getMin(iter->second, a[iter->first]);
			while (po--) {
				ans *= iter->first;
				if (ans > LIMIT) {
					ans %= LIMIT;
					isOver = true;
				}
			}
		}
	}
	
	if (isOver) {
		cout.width(9);
		cout.fill('0');
		ans %= LIMIT;
		cout << ans << endl;
	}
	else cout << ans << endl;
	
	return 0;
}