#include <iostream>

using namespace std;
int arr[19][19];
int winner = 0, winner_x, winner_y;
void check(int x, int y) {

	int turn = arr[y][x];
	int cnt = 0;
	int cy = y, cx = x;


	//horizontal
	if (cx == 0 || arr[cy][cx - 1] != turn) {
		while (arr[cy][cx] == turn) {
			cnt++;
			if (cx + 1 < 19) {
				cx++;
			}
			else break;
		}

		if (cnt == 5) {
			winner = turn;
			winner_x = x; winner_y = y;
		}
	}


	//vertical
	cy = y, cx = x;
	cnt = 0;
	if (cy == 0 || arr[cy - 1][cx] != turn) {
		while (arr[cy][cx] == turn) {
			cnt++;
			if (cy + 1 < 19) cy++;
			else break;
		}

		if (cnt == 5) {
			winner = turn;
			winner_x = x; winner_y = y;
		}
	}
	

	//diagonal down right
	cy = y, cx = x;
	cnt = 0;
	if ((cy == 0 && cx == 0) || arr[cy - 1][cx - 1] != turn) {
		while (arr[cy][cx] == turn) {
			cnt++;
			if (cy + 1 < 19 && cx + 1 < 19) {
				cy++;
				cx++;
			}
			else break;
		}

		if (cnt == 5) {
			winner = turn;
			winner_x = x; winner_y = y;
		}
	}

	//diagonal up right
	cy = y, cx = x;
	cnt = 0;
	if ((cx == 0 || cy == 18) || arr[cy + 1][cx - 1] != turn) {
		while (arr[cy][cx] == turn) {
			cnt++;
			if (cy - 1 >= 0 && cx + 1 < 19) {
				cy--;
				cx++;
			}
			else break;
		}

		if (cnt == 5) {
			winner = turn;
			winner_x = x, winner_y = y;
		}
	}

}
int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (winner) continue;
			check(j, i);
		}
	}

	cout << winner << "\n";
	if (winner > 0) {
		cout << winner_y + 1 << " " << winner_x + 1 << "\n";
	}

	return 0;
}