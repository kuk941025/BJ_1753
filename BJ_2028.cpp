#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string strM, strS;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		strM = to_string(num * num);
		strS = to_string(num);
		int lenM, lenS;
		lenM = strM.length(); lenS = strS.length();
		
		int cnt = 0;
		int j = 0;
		for (int i = lenM - lenS; i < lenM; i++) {

			if (strM[i] == strS[j++]) cnt++;
			
		}
		if (cnt == lenS) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}