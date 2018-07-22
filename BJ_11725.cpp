#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;
vector <vector <int>> tree;
int parent[100010] = { 0 };
int main() {
	queue <int> q;
	int N;
	cin >> N;
	tree.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int n, c;
		cin >> n >> c;
		tree[n].push_back(c);
		tree[c].push_back(n);
	}
	q.push(1);
	parent[1] = 1;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (int i = 0; i < tree[node].size(); i++) {
			if (parent[tree[node][i]] == 0) {
				parent[tree[node][i]] = node;
				q.push(tree[node][i]);
			}
		}
	}
	for (int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
	return 0;
}