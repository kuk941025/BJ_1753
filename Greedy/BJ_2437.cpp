#include <iostream>
#include <algorithm>

using namespace std;
int arr[1010], N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + 1 < arr[i]) break;
		sum += arr[i];
	}
	cout << sum + 1 << "\n";
	return 0;
}