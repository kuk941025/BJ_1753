#include <iostream>
#include <string>
#include <limits.h>

using namespace std;
inline int getMin(int a, int b) { return a > b ? b : a; }
int ans = INT_MAX;
string map[50];
string w[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};
string b[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};


int N, M;

int cntBlack(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[y + i][x + j] != b[i][j]) cnt++;
		}
	}

	return cnt;
}
int cntWhite(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[y + i][x + j] != w[i][j]) cnt++;
		}
	}

	return cnt;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			ans = getMin(ans, getMin(cntBlack(j, i), cntWhite(j, i)));
		}
	}

	cout << ans;

	return 0;
}