#include <iostream>
#include <limits.h>

using namespace std;

int ans = INT_MIN, maxIdx = -1;

int main() {
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int num; cin >> num;
			sum += num;
		}

		if (sum > ans) {
			maxIdx = i + 1;
			ans = sum;
		}
	}

	cout << maxIdx << " " << ans << "\n";
	return 0;
}