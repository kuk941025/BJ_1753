#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
int ans = 0;
using namespace std;
void solve(int base, int target_y, int target_x, int lvl) {
	int width = pow(2, lvl);
	
	int div = width / 2;
	if (lvl == 1) {
		if (target_y == 0 && target_x == 0) ans = base;
		else if (target_y == 0 && target_x == 1) ans = base + 1;
		else if (target_y == 1 && target_x == 0) ans = base + 2;
		else if (target_y == 1 && target_x == 1) ans = base + 3;
		
		return;
	}
	int base_change = pow(4, lvl - 1);
	if (target_y < div && target_x < div) {
		//case 1
		solve(base, target_y, target_x, lvl - 1);
	}
	else if (target_y < div && target_x >= div) {
		//case 2
		solve(base + 1 * base_change, target_y, target_x - div, lvl - 1);
	}
	else if (target_y >= div && target_x < div) {
		//case 3
		solve(base + 2 * base_change, target_y - div, target_x, lvl - 1);
	}
	else {
		//case 4
		solve(base + 3 * base_change, target_y - div, target_x - div, lvl - 1);
	}
}
int main() {
	int n, r, c;
	int base_x, base_y;
	cin >> n >> r >> c;
	solve(0, r, c, n);

	cout << ans << endl;
	return 0;
}