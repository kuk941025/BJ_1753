#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;
int main() {
	string tar;

	int N, cnt;
	cin >> tar;
	cin >> N;
	cnt = 0;
	int t_len = tar.length();
	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		for (int i = 0; i < t_len - 1; i++)
			in = in + in[i];

		if (in.find(tar) != -1) { cnt++; continue; }
	}
	cout << cnt;
	return 0;
}