#include <iostream>


using namespace std;
int N, M;
int arr[60][60];
int cnt = 0;
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int getNext(int d) {
	return d - 1 >= 0 ? d - 1 : 3;
}
int getOpp(int d) {
	switch (d) {
	case 0:
		return 2;
	case 1:
		return 3;
	case 2:
		return 0;
	case 3:
	default:
		return 1;
	}
}
void solve(int x, int y, int d) {
	if (arr[y][x] == 1) return;

	if (arr[y][x] == 0) {
		cnt++;
		arr[y][x] = 2;
	}
	for (int i = 0; i < 4; i++) {
		d = getNext(d);
		int nx = x + dir[d][0], ny = y + dir[d][1];
		if (nx < 0 || ny < 0) continue;
		if (arr[ny][nx] == 0) {
			solve(nx, ny, d);
			return;
		}

	}

	int bd = getOpp(d);
	solve(x + dir[bd][0], y + dir[bd][1], d);
}
int main() {
	int sx, sy, sd;
	cin >> N >> M;
	cin >> sx >> sy >> sd;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	solve(sy, sx, sd);

	cout << cnt << "\n";
	
	return 0;
}