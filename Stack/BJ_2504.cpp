#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector <int> st;
	string in;
	
	cin >> in;
	int len = in.length();
	for (int i = 0; i < len; i++) {
		if (in[i] == '(' || in[i] == '[') st.push_back(in[i]);
		else {
			if (st.empty()) {
				cout << "0";
				return 0;
			}
			int sum = 0;
			if (in[i] == ')') {
				int pop = st.back();
				st.pop_back();
				while (pop != '(') {
					if (pop == '[') {
						cout << "0";
						return 0;
					}
					sum += pop - 100;
					if (st.size() == 0) {
						cout << "0";
						return 0;
					}
					pop = st.back();
					st.pop_back();
				}
								
				if (sum == 0) sum = 1;
				st.push_back(sum * 2 + 100);
			}
			else if (in[i] == ']') {
				int pop = st.back();
				st.pop_back();
				while (pop != '[') {
					if (pop == '(') {
						cout << "0";
						return 0;
					}
					sum += pop - 100;
					if (st.size() == 0) {
						cout << "0";
						return 0;
					}
					pop = st.back();
					st.pop_back();
				}

				if (sum == 0) sum = 1;
				st.push_back(sum * 3 + 100);
			}
			else { //number
				st.push_back(in[i] - '0' + 100);
			}
		}
	}
	int res = 0;
	int size = st.size();
	for (int i = 0; i < size; i++) {
		if (st[i] < 100) {
			cout << "0";
			return 0;
		}
	}
	while (!st.empty()) {
		res += st.back() - 100;

		st.pop_back();
	}
	cout << res << "\n";
	return 0;
}