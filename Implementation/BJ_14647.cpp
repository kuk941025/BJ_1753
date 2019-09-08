#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;
int in[510][510] = { 0 };
int total[510][2] = { 0 };
int main() {
	int n, m, cnt, sum;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> in[i][j];
	int max;
	max = sum = 0;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < m; j++) {
			string strN = to_string(in[i][j]);
			int len = strN.length();

			for (int k = 0; k < len; k++) {
				if (strN[k] == '9') cnt++;
			}
		}
		total[i][0] = cnt;
		sum += cnt;
		if (cnt > max) max = cnt;
	}
	for (int i = 0; i < m; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			string strN = to_string(in[j][i]);
			int len = strN.length();
			for (int k = 0; k < len; k++)
				if (strN[k] == '9') cnt++;
		}
		total[i][1] = cnt;
		if (cnt > max) max = cnt;
	}
	cout << sum - max << endl;
	return 0;
}