#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n, maxcost;
	int freq[7];
	cin >> n;
	maxcost = 0;
	while (n--) {
		memset(freq, 0, sizeof(freq));
		
		for (int i = 0; i < 3; i++) {
			int in; cin >> in;
			freq[in]++;
		}
		int max = 0, cost = 0;
		int maxIdx = 0;
		for (int i = 1; i <= 6; i++) {
			if (freq[i] >= max) { max = freq[i]; maxIdx = i; }
		}
		if (max == 3) {
			cost = 10000 + maxIdx * 1000;
		}
		else if (max == 2) {
			cost = 1000 + maxIdx * 100;
		}
		else {
			cost = maxIdx * 100;
		}
		if (cost > maxcost) maxcost = cost;
		
	}

	cout << maxcost << "\n";
	return 0;
}