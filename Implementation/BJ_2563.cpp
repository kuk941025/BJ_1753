#include <iostream>

using namespace std;
int arr[100][100] = { 0 };
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				arr[k][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) ans++;
		}
	}

	cout << ans;
	return 0;
}