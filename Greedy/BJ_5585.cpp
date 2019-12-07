#include <iostream>

using namespace std;

int changes[] = {500, 100, 50, 10, 5, 1};
int main() {
	int amount;
	cin >> amount;
	int remaining = 1000 - amount;
	int change_idx, cnt;
	change_idx = cnt = 0;

	while (remaining > 0) {
		//find amount of change to be used.
		while (changes[change_idx] > remaining) {
			change_idx++;
		}

		remaining -= changes[change_idx];
		cnt++;
	}

	cout << cnt;
	return 0;
}