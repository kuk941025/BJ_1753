#include <iostream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

int N, M;
int arr[20][20], copied[20][20];
vector<pair<int, int>> viruses;
int max_area = 0;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0]; int next_x = x + dir[i][1];
		if (copied[next_y][next_x] == 0) {
			copied[next_y][next_x] = 2;
			dfs(next_x, next_y);
		}
	}
}
void brute(int depth) {
	if (depth == 3) {
		memcpy(copied, arr, sizeof arr);
	
		for (auto virus : viruses) {
			dfs(virus.first, virus.second);
		}

		//count zeros
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (copied[i][j] == 0) cnt++;
			}
		}
		if (cnt > max_area) max_area = cnt;
		return;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				brute(depth + 1);
				arr[i][j] = 0;
			}
		}
	}

}
int main() {
	cin >> N >> M;;

	memset(arr, -1, sizeof arr);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				viruses.push_back(make_pair(j, i));
			}
		}
	}


	brute(0);
	cout << max_area;

	return 0;
}