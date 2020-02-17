#include <iostream>

using namespace std;
int f(int num) {
	if (num <= 1) return 1;
	else return f(num - 1) * num;
}
int main() {
	int n, k;
	cin >> n >> k;

	cout << f(n) / (f(k)*f(n - k)) << endl;
	return 0;
}