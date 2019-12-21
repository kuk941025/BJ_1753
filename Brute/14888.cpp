#include <iostream>
#include <limits.h>
using namespace std;
int nums[20];
int ans_max = INT_MIN, ans_min = INT_MAX, res = 0;

void dfs(int add, int sub, int mul, int div, int idx, int res) {
	if (add == 0 && sub == 0 && mul == 0 && div == 0) {
		if (res > ans_max) ans_max = res;
		if (res < ans_min) ans_min = res;

		return;
	}

	if (add > 0) {
		dfs(add - 1, sub, mul, div, idx + 1, res + nums[idx + 1]);
		
	}
	if (sub > 0) {
		dfs(add, sub - 1, mul, div, idx + 1, res - nums[idx + 1]);
	}
	if (mul > 0) {
		dfs(add, sub, mul - 1, div, idx + 1, res * nums[idx + 1]);
	}
	if (div > 0) {
		dfs(add, sub, mul, div - 1, idx + 1, res / nums[idx + 1]);
	}
}
int main() {
	int n;
	int add, sub, mul, div;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	cin >> add >> sub >> mul >> div;


	dfs(add, sub, mul, div, 0, nums[0]);

	cout << ans_max << endl << ans_min;
	return 0;
}
