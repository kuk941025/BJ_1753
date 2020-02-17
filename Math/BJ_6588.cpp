#include <iostream>
#include <math.h>

using namespace std;
int arr[1000010] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] == -1) continue;
		for (int j = i + i; j <= 1000000; j += i) arr[j] = -1;
	}

	while (1) {
		int num; cin >> num;
		if (num == 0) break;

		bool found = false;
		for (int i = 2; i <= num / 2; i++) {
			if (arr[i] == -1) continue;
			
			if (arr[num - i] == 0) {
				cout << num << " = " << i << " + " << num - i << "\n";
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}
	return 0;
}