#include <iostream>

using namespace std;

int scores[60];

int main() {
	int score;
	for (int i = 0; i < 50; i++) cin >> scores[i];

	cin >> score;
	int rank;
	for (int i = 0; i < 50; i++) {
		if (score == scores[i]) {
			rank = i + 1;
			break;
		}
	}

	if (rank >= 49) cout << "F";
	else if (rank >= 46) cout << "C0";
	else if (rank >= 36) cout << "C+";
	else if (rank >= 31) cout << "B0";
	else if (rank >= 16) cout << "B+";
	else if (rank >= 6) cout << "A0";
	else cout << "A+";

	return 0;
}