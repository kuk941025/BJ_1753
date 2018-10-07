#include <iostream>
#include <stdio.h>
using namespace std;
int in[4];

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) cin >> in[j];
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (in[j] == 0) cnt++;
		}
		if (cnt == 0) printf("E\n");
		else printf("%c\n", 'A' + (cnt - 1));
	}
	
	return 0;
}