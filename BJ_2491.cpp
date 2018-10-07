#include <iostream>

using namespace std;
int in[100010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> in[i];
	
	if (n == 1) { cout << "1"; return 0; }
	int cnt1, cnt2;
	int max1, max2;
	cnt1 = cnt2 = max1 = max2 = 1;
	
	for (int i = 0; i < n - 1; i++) {
		if (in[i] == in[i + 1]) {
			cnt1++;
			cnt2++;
		}
		if (in[i + 1] > in[i]) {
			cnt1++;
			cnt2 = 1;
		}
		else if (in[i + 1] < in[i]) {
			cnt2++;
			cnt1 = 1;
		}
		
		if (cnt1 > max1) max1 = cnt1;
		if (cnt2 > max2) max2 = cnt2;
	}

	cout << (max1 > max2 ? max1 : max2);

	return 0;
}