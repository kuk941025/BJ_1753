#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

struct coord {
	int x, y, cnt;
};

using namespace std;
char arr[60][60];
int R, K, visited[60][60] = { 0 };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
inline int getMin(int a, int b) { return a > b ? b : a; }
int main() {
	queue <coord> q;
	vector <coord> water;
	cin >> R >> K;

	coord start, end;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= K; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				start.x = j; start.y = i; start.cnt = 0;
			}
			else if (arr[i][j] == 'D') {
				end.x = j; end.y = i; end.cnt = INT_MAX;
			}
		}
	}

	q.push(start);
	int updated_at = -1;

	while (!q.empty()) {
		coord out = q.front(); q.pop();

		if (out.x == end.x && out.y == end.y) {
			end.cnt = getMin(end.cnt, out.cnt);
			continue;
		}

		//update only when count changes
		if (out.cnt > updated_at) {
			updated_at++;
			//mark where water will be filled.
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= K; j++) {
					if (arr[i][j] == '*') {
						water.push_back({ j, i, 0 });
					}
				}
			}
			
			for (auto pos : water) {
				for (int i = 0; i < 4; i++) {
					int ny = pos.y + dir[i][0];
					int nx = pos.x + dir[i][1];
					if (arr[ny][nx] == '.') {
						arr[ny][nx] = '*';
					}
				}
			}
			
		}
		

		//move character
		for (int i = 0; i < 4; i++) {
			int ny = out.y + dir[i][0];
			int nx = out.x + dir[i][1];
			if ((arr[ny][nx] == '.' || arr[ny][nx] == 'D') && visited[ny][nx] == 0) {
				q.push({ nx, ny, out.cnt + 1 });
				visited[ny][nx] = 1;
			}
		}                                    

		
	}

	if (end.cnt == INT_MAX) cout << "KAKTUS" << "\n";
	else cout << end.cnt << "\n";

	return 0;
}