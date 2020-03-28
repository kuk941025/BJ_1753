#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
vector<pair<int, int>> v;
int N, n;

bool csort(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first ? false : true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> n;


	while (n--) {
		int num; cin >> num;
		int size = v.size();
		//search for num
		bool isFound = false;

		for (int i = 0; i < size; i++) {
			if (v[i].first == num) {
				v[i].second++;
				isFound = true;
				break;
			}
		}


		if (!isFound) {
			if (size < N) {
				v.push_back(make_pair(num, 0));
			}
			else {
				int minValue = INT_MAX, minIdx = 0;
				
				for (int i = 0; i < size; i++) {
					if (v[i].second < minValue) {
						minIdx = i;
						minValue = v[i].second;
					}

				}

				v.erase(v.begin() + minIdx);
				v.push_back(make_pair(num, 0));
			}
		}
	}

	sort(v.begin(), v.end(), csort);
	for (auto out : v) {
			cout << out.first << " ";
		}
	cout << "\n";
	return 0;
}