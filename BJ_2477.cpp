#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> v;
int det[][4] = { {3, 1, 3}, {1, 4, 1}, {4, 2, 4}, {2, 3, 2,} };
int main() {
	int num, n = 6;
	cin >> num;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	int idx = -1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			int cnt = 0;
			for (int k = 0; k < 3; k++) {
				if (v[(i + k) % 6].first == det[j][k]) { cnt++;}
			}
			if (cnt == 3) { idx = j; break; }
		}
	}
	int minus_area = 0;
	for (int i = 0; i < 6; i++) {
		if (v[i].first == det[idx][1] && v[(i + 1) % 6].first == det[idx][2]) {
			minus_area = v[i].second * v[(i + 1) % 6].second;
			break;
		}
	}
	int height, width;
	height = width = 0;
	for (int i = 0; i < 6; i++) {
		if (v[i].first == 1) width += v[i].second;
		if (v[i].first == 3) height += v[i].second;
	}
	int area = height * width - minus_area;
	cout << area * num << "\n";
	return 0;
}