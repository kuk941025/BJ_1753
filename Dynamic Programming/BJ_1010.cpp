#include <iostream>

using namespace std;

int memo[31][31] = { 0 };
int main() {
	
	//fill first row
	for (int i = 1; i < 31; i++) {
		memo[1][i] = i;
	}

	for (int i = 2; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			for (int k = i - 1; k < j; k++) {
				memo[i][j] += memo[i - 1][k];
			}
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << memo[N][M] << "\n";
	}
	return 0;
}