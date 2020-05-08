#include <iostream>
#include <string>
#include <queue>
#include <string.h>

using namespace std;
int N, visited[110][110];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
char a[110][110];
queue<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string in; cin >> in;
		for (int j = 1; j <= N; j++) {
			a[i][j] = in[j - 1];
		}
	}

	int rc, bc, gc;
	rc = bc = gc = 0;
	//check red and green
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) continue;

			if (a[i][j] == 'R') {
				visited[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					auto out = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = out.first + dir[k][0];
						int nx = out.second + dir[k][1];
						
						if (!visited[ny][nx] && a[ny][nx] == 'R') {
							visited[ny][nx] = 1;
							q.push({ ny, nx });
						}
					}
				}
				rc++;
			}
			else if (a[i][j] == 'G'){
				visited[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					auto out = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = out.first + dir[k][0];
						int nx = out.second + dir[k][1];

						if (!visited[ny][nx] && a[ny][nx] == 'G') {
							visited[ny][nx] = 1;
							q.push({ ny, nx });
						}
					}
				}
				gc++;
			}
			else {
				visited[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					auto out = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = out.first + dir[k][0];
						int nx = out.second + dir[k][1];

						if (!visited[ny][nx] && a[ny][nx] == 'B') {
							visited[ny][nx] = 1;
							q.push({ ny, nx });
						}
					}
				}
				bc++;
			}
		}
	}
	int all = rc + gc + bc;

	rc = gc = bc = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) continue;

			if (a[i][j] == 'R' || a[i][j] == 'G') {
				visited[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					auto out = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = out.first + dir[k][0];
						int nx = out.second + dir[k][1];

						if (!visited[ny][nx] && (a[ny][nx] == 'R' || a[ny][nx] == 'G')) {
							visited[ny][nx] = 1;
							q.push({ ny, nx });
						}
					}
				}
				rc++;
			}
			else {
				visited[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					auto out = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = out.first + dir[k][0];
						int nx = out.second + dir[k][1];

						if (!visited[ny][nx] && a[ny][nx] == 'B') {
							visited[ny][nx] = 1;
							q.push({ ny, nx });
						}
					}
				}
				bc++;
			}
		}
	}
	cout << all << " " << rc + bc << "\n";
	return 0;
}