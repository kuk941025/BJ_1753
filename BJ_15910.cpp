#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int dp[100010][7] = { -1 };
string base = "BANANA";
inline int min(int a, int b) { return a > b ? b : a; }
int main() {
	string in;
	cin >> in;
	
	int len = in.length();
	for (int i = 0; i <= len; i++) for (int j = 0; j <= 6; j++) dp[i][j] = INT_MAX;

	dp[0][0] = 0;
	for (int i = 1; i <= len; i++) {
		int loop = i;
		if (loop >= 6) loop = 6;
		for (int j = 1; j <= loop; j++) {
			if (j == 1)
				dp[i][j] = min(dp[i - 1][1], min(dp[i - 1][0], dp[i - 1][6])) + (in[i - 1] != 'B');
			else if (j == 5)
				dp[i][j] = min(dp[i - 1][4], dp[i - 1][6]) + (in[i - 1] != 'N');
			else
				dp[i][j] = dp[i - 1][j - 1] + (in[i - 1] != base[j - 1]);
		}
	}


	cout << dp[len][6];
	return 0;
}