#include <iostream>
#include <queue>

using namespace std;
int visited[1000010];
int F, S, G, U, D;
class Count {
public:
	int pos, cnt;
	Count(int pos, int cnt) {
		this->pos = pos;
		this->cnt = cnt;
	}
};

queue<Count> q;
int main() {
	cin >> F >> S >> G >> U >> D;

	q.push({ S, 0 });
	visited[S] = 1;
	int ans = -1;
	while (!q.empty()) {
		Count out = q.front(); q.pop();
	
		if (out.pos == G) {
			ans = out.cnt;
			break;
		}

		if (out.pos + U <= F && visited[out.pos + U] == 0 ) {
			visited[out.pos + U] = 1;
			q.push({ out.pos + U, out.cnt + 1 });
		}
		if (out.pos - D > 0 && visited[out.pos - D] == 0) {
			visited[out.pos - D] = 1;
			q.push({ out.pos - D, out.cnt + 1 });
		}
	}

	if (ans == -1) cout << "use the stairs\n";
	else cout << ans << "\n";
	return 0;
}