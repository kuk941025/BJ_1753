#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
int L, C;
char arr[16], vowels[] = { 'a', 'e', 'i', 'o', 'u' };
int visited[16] = { 0 };
vector<char> v;

void dfs(int vo, int nv, int idx) {

	if (vo <= 0 && nv <= 0 && v.size() == L) {

		for (auto out : v) {
			cout << out;
		}
		cout << "\n";
		return;
	}


	for (int i = idx; i < C; i++) {

		bool isVowel = false;
		for (int j = 0; j < 5; j++) {
			if (arr[i] == vowels[j]) {
				isVowel = true; break;
			}
		}

		if (isVowel) {
			v.push_back(arr[i]);
			dfs(vo - 1, nv, i + 1);
			v.pop_back();

		}
		else {
			v.push_back(arr[i]);
			dfs(vo, nv - 1, i + 1);
			v.pop_back();

		}

	}
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> arr[i];
	sort(arr, arr + C);

	dfs(1, 2, 0);
	return 0;
}