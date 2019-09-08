#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> v;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int sovled, score;
		cin >> sovled >> score;
		v.push_back(make_pair(sovled, score));
	}
	sort(v.begin(), v.end(), cmp);
	int n = v[4].first, cnt = 0;
	for (int i = 5; i < v.size() && v[i].first == n; i++) 
		cnt++;
	cout << cnt << "\n";
	return 0;
}