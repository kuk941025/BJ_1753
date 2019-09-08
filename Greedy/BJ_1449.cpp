#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;
int in[1010];
int main() {
	int N, len;
	float s, e;
	cin >> N >> len;
	for (int i = 0; i < N; i++) cin >> in[i];
	sort(in, in + N);
	
	int cnt = 1;
	s = in[0] - 0.5;
	e = s + len;
	for (int i = 0; i < N; i++) {
		if (in[i] - 0.5 >= s && in[i] + 0.5 <= e) continue;
		else {
			cnt++;
			s = in[i] - 0.5;
			e = s + len;
		}
	}
	cout << cnt;
	return 0;

}