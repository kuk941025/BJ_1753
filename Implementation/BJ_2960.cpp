#include <iostream>

using namespace std;
int N, K, arr[1010] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int cnt = 0, n = 2;
	while (1) {
		for (int i = n; i <= N; i += n) {
			if (arr[i] == -1) continue;
			if (++cnt >= K) {
				cout << i << endl;
				return 0;
			}
			arr[i] = -1;
		}
		n++;
	}
	
	return 0;
}