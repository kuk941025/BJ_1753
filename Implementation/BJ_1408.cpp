#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int h1, h2, m1, m2, s1, s2;
	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);
	s2 -= s1;
	if (s2 < 0) { m2--; s2 += 60; }
	m2 -= m1;
	if (m2 < 0) { h2--; m2 += 60; }
	h2 -= h1;
	if (h2 < 0) { h2 += 24; }
	printf("%02d:%02d:%02d\n", h2, m2, s2);
	return 0;
}