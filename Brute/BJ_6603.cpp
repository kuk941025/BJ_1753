#include <iostream>
#include <string.h>
#include <vector>


using namespace std;
int N, arr[15];
vector <int> seq;

void dfs(int idx, int rem) {
	if (rem == 0) {
		for (auto num : seq)
			cout << num << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		seq.push_back(arr[i]);
		dfs(i + 1, rem - 1);
		seq.pop_back();
	}
}
int main() {
	while (1) {
		cin >> N;
		if (N == 0) break;


		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		dfs(0, 6);
		cout << "\n";
		
	}
	return 0;
}