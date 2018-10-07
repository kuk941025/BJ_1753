#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;
int in[70][70];
int dir[][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
void solve(int x, int y, int len) {
	if (len == 1) {
		cout << in[y][x];
		return;
	}


	int base = in[y][x];
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if (base != in[i][j]) {
				int half = len / 2;
				cout << "(";
				for (int k = 0; k < 4; k++) {
					
					solve(x + half*dir[k][1], y + half*dir[k][0], half);
					
				}
				cout << ")";
				return;
			}
		}
	}
	cout << base;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &in[i][j]);
	}


	solve(0, 0, n);
	return 0;
}