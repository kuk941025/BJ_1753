#include <iostream>
#include <string>
using namespace std;
char alpha[][4] = { {" "}, {'A', 'B', 'C', ' '}, {'D', 'E', 'F', ' '}, {'G', 'H', 'I', ' '},
{'J', 'K', 'L', ' '}, {'M', 'N', 'O', ' '}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V', ' '}, {'W', 'X', 'Y', 'Z'} };
int main() {
	int t, tt; cin >> t >> tt;
	string in;
	getline(cin >> ws, in);
	int size = in.size();
	int cnt = 0;
	int prev = 0;
	for (int i = 0; i < size; i++) {
		if (in[i] == ' ') {
			cnt += t;
			prev = ' ';
		}
		else {
			for (int j = 1; j < 9; j++) {
				for (int k = 0; k < 4; k++) {
					if (alpha[j][k] == in[i]) {
						if (prev == j) cnt += tt;
						cnt += (t * (k + 1));
						prev = j;
						break;
					}
				}
			}
		}

	}

	cout << cnt;
	return 0;
}