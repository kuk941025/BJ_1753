#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	int cnt = 0;
	cin >> n >> m >> k;

	//find out possible number of teams w/o k.
	while (n >= 2 && m >= 1) {
		n -= 2;
		m--;
		cnt++;
	}

	//subtract intern numbers
	k = k - (n + m); //subtract remainings
	while (k > 0) {
		k -= 3;
		cnt--;
	}

	cout << cnt;
	return 0;
}