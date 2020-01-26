#include <iostream>
#include <limits.h>

using namespace std;
int T;
inline int getMax(int a, int b) { return a > b ? a : b; }
inline int getMin(int a, int b) { return a > b ? b : a; }

int main() {
	cin >> T;
	while (T--) {
		int L, n;
		int max = INT_MIN, min = INT_MIN;
		                                      
		cin >> L >> n;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			min = getMax(min, getMin(num, L - num));
			max = getMax(max, getMax(num, L - num));
		};

		cout << min << " " << max << "\n";
	}

	return 0;
}