#include <iostream>
#include <vector>
using namespace std;
long long fib[50] = { 0 };
int main() {
	
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < 50; i++) fib[i] = fib[i - 2] + fib[i - 1];
	int N;
	cin >> N;
	while (N--)	 {
		vector <int> ans;
		int tar;
		cin >> tar;
		while (tar > 0) {
			int idx = 0;
			for (; fib[idx] <= tar; idx++);
			idx--;
			ans.push_back(fib[idx]);
			tar -= fib[idx];
			
		}
		while (!ans.empty()) {
			printf("%d ", ans.back()); ans.pop_back();
		}
		printf("\n");
	}
	return 0;
}