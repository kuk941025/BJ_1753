#include <iostream>
#include <string>

using namespace std;

string base[] = {"sukhwan", "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby"};
const int word = 14;

int main() {
	int N;
	cin >> N;
	int repeated, mod;

		repeated = N / word; mod = N % word;
		if (base[mod] == "tururu") {
			if (repeated >= 3) cout << "tu+ru*" << repeated + 2;
			else {
				cout << base[mod];
				for (int i = 0; i < repeated; i++)
					cout << "ru";
			}
		}
		else if (base[mod] == "turu") {
			if (repeated >= 4) cout << "tu+ru*" << repeated + 1;
			else {
				cout << base[mod];
				for (int i = 0; i < repeated; i++) cout << "ru";
			}
		}
		
	
		else cout << base[mod];
		cout << "\n";
	

	return 0;
}