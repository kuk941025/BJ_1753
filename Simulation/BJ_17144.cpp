#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;
int R, C, T, arr[60][60];
int updated[60][60];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<pair<int, int>> m;

void spread() {
	memset(updated, 0, sizeof updated);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] > 0) {
				//spread
				int cnt_spread = 0;
				for (int k = 0; k < 4; k++) {
					int next_y = i + dir[k][0]; int next_x = j + dir[k][1];

					if (arr[next_y][next_x] >= 0) {
						//if spreadable.
						cnt_spread++;
						updated[next_y][next_x] += arr[i][j] / 5;
					}
				}

				//after update, update arr[i][j] value
				arr[i][j] -= arr[i][j] / 5 * cnt_spread;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			arr[i][j] += updated[i][j];
		}
	}
}

void circulate() {
	int first_y = m[0].second; 
	int second_y = m[1].second;
	
	memcpy(updated, arr, sizeof updated);
	
	//to right
	for (int i = 2; i <= C; i++) {
		if (i - 1 == 1) {
			updated[first_y][i] = updated[second_y][i] = 0;
		}
		else {
			updated[first_y][i] = arr[first_y][i - 1];
			updated[second_y][i] = arr[second_y][i - 1];
		}

	}

	//up
	for (int i = first_y - 1; i >= 1; i--) {
		updated[i][C] = arr[i + 1][C];
	}
	//down
	for (int i = second_y + 1; i <= R; i++) {
		updated[i][C] = arr[i - 1][C];
	}

	//to the left
	for (int i = C - 1; i >= 1; i--) {
		updated[1][i] = arr[1][i + 1];
		updated[R][i] = arr[R][i + 1];
	}

	//down
	for (int i = 2; i < first_y; i++) {
		updated[i][1] = arr[i - 1][1];
	}
	updated[first_y][1] = -1;

	//up
	for (int i = R - 1; i > second_y; i--) {
		updated[i][1] = arr[i + 1][1];
	}
	updated[second_y][1] = -1;


	//update original array
	memcpy(arr, updated, sizeof updated);
}
int main() {
	cin >> R >> C >> T;

	memset(arr, -1, sizeof arr);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) m.push_back(make_pair(j, i));
		}
	}

	while (T--)
	{
		spread();
		circulate();
	}


	//print
	int cnt = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] > 0) cnt += arr[i][j];
		}
	}


	cout << cnt;
	return 0;
}