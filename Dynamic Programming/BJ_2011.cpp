#include <iostream>
#include <string>

using namespace std;
int arr[5010], dp[5010];
int main() {
	string in; cin >> in;
	int len = in.length();
	for (int i = 1; i <= len; i++) arr[i] = in[i - 1] - '0';
	

	dp[0] = dp[1] = 1;
	for (int i = 1; i <= len; i++) {
		if (arr[i] != 0)
			dp[i] = dp[i - 1] % 1000000;

		int temp = arr[i] + arr[i - 1] * 10;
		if (temp >= 10 && temp <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	if (arr[1] == 0) cout << "0";
	else cout << dp[len] << "\n";
	return 0;
}