#include <iostream>
#include <string>

using namespace std;

int k, n;
int main() {
	cin >> k >> n;
	string res, map[1010];
	cin >> res;
	int mid = -1;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		if (mid == -1 && map[i][0] == '?') mid = i;
	}
	   
	string start;

	//set up start string
	for (int i = 0; i < k; i++) {
		start.push_back('A' + i);
	}
	for (int i = 0; i < mid; i++) {
		for (int j = 0; j < k; j++) {
			if (map[i][j] == '-') {
				swap(start[j], start[j + 1]);
			}
		}
	}

	for (int i = n - 1; i > mid; i--) {
		for (int j = 0; j < k; j++) {
			if (map[i][j] == '-') {
				swap(res[j], res[j + 1]);
			}
		}
	}

	//check if match
	string ans;
	for (int i = 0; i < k; i++) {
		if (res[i] == start[i]) ans.push_back('*');
		else if (start[i] == res[i + 1]) {
			ans.push_back('-');
			ans.push_back('*');
			i++;
					
		}
		else {
			for (int j = 0; j < k - 1; j++) {
				cout << "x";
			}
			return 0;
		}
	}

	for (int i = 0; i < k - 1; i++) cout << ans[i];

	return 0;
}