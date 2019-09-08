#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
//print 111x ^ 2 + 11x + 1

int main() {
	int n;
	cin >> n;
	int res = 111 * n * n + 11 * n + 1;
	cout << res << endl;
	return 0;
}