#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
	return a < b;
}
int N, M, arr[300010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N + 1, cmp);

	
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}
	return 0;
}