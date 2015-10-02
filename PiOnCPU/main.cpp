#include "functions.h"
#include <cstdio>

int main()
{
	unsigned char a[5] = { 111, 20, 12, 222, 133 };
	char b[11] = { 0 };
	DecToHexArray(a, b, 5);
	printf("%s\n", b);
}