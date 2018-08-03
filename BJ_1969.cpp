#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
vector <string> in;
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		in.push_back(input);
	}
	string out;
	for (int i = 0; i < M; i++) {
		int freq[26];
		memset(freq, 0, sizeof(freq));
		for (int j = 0; j < N; j++) {
			freq[in[j][i] - 'A']++;
		}
		int max, maxIdx;
		max = maxIdx = -1;
		for (int j = 0; j < 26; j++) {
			if (freq[j] > max) {
				max = freq[j];
				maxIdx = j;
			}
		}
		
		out.push_back('A' + maxIdx);
	}
	cout << out << "\n";
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (in[i][j] != out[j]) cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}