#include <iostream>

using namespace std;
char arr[1000010] = { 0 };
int J, a, ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> J >> a;
	for (int i = 1; i <= J; i++) cin >> arr[i];

	char in; int size;
	while (a--) {
		cin >> in >> size;
		if (arr[size] == 'X') continue;
		switch (in) {
		case 'S':
			if (arr[size] != 'X') {
				ans++;
				arr[size] = 'X';
				break;
			}
		case 'M':
			if (arr[size] == 'M' || arr[size] == 'L') {
				ans++;
				arr[size] = 'X';
				break;
			}
		case 'L':
			if (arr[size] == 'L') {
				ans++;
				arr[size] = 'X';
				break;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}