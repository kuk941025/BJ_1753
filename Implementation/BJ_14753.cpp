#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v;
bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), compare);
	int num1 = v[0] * v[1];
	int num2 = v[N - 1] * v[N - 2];

	int num3 = v[0] * v[1] * v[2];
	int num4 = v[0] * v[N - 1] * v[N - 2];

	cout << max({ num1, num2, num3, num4 }) << "\n";
	return 0;
}