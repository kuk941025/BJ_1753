#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
class Coord {
public:
	int x, y, cnt;
	Coord(int x, int y, int cnt) {
		this->x = x;
		this->y = y;
		this->cnt = cnt;
	}
};

queue<Coord> q;
int T, N;
int visited[310][310];
int dy[8] = { -1,-2,-2,-1,1,2,1,2 };
int dx[8] = { -2,-1,1,2,-2,-1,2,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		int sx, sy, ex, ey;
		cin >> N >> sx >> sy >> ex >> ey;


		q.push(Coord(sx, sy, 0));
		visited[sy][sx]++;
		while (!q.empty()) {
			Coord out = q.front(); q.pop();
	
			if (out.x == ex && out.y == ey) {
				cout << out.cnt << "\n";
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = out.x + dx[i];
				int ny = out.y + dy[i];

				if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) continue;
				if (visited[ny][nx]) continue;

				visited[ny][nx] = 1;
				q.push(Coord(nx, ny, out.cnt + 1)	);

			}
		}

		q = queue<Coord>();
	
	}

	return 0;
}