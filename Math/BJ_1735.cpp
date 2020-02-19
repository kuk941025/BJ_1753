#include <iostream>

using namespace std;
int gcd(int a, int b) {

	while (b > 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int de = lcm(b, d);
	a *= (de / b);
	c *= (de / d);
	int nu = a + c;

	int gc = gcd(nu, de);
	cout << (a + c) / gc << " " << de / gc << endl;

	return 0;
}