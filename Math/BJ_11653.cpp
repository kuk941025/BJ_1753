#include <iostream>
#include <math.h>

using namespace std;
int N;

int main() {
	cin >> N;
	for (int i = 2; i <= sqrt(N); i++) {
		while (N % i == 0) {
			cout << i << "\n";
			N /= i;
		}
	}

	if (N != 1) cout << N << "\n";
	return 0;
}