#include <iostream>
#include <string.h>

using namespace std;

int arr[110][110];
int visited[110], N;
void dfs(int node) {
	for (int i = 0; i < N; i++) {
		if (arr[node][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	memset(arr, 0, sizeof(arr));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);

		for (int j = 0; j < N; j++) cout << visited[j] << " ";
		cout << "\n";
	}

	return 0;
}