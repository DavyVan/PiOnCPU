#include "functions.h"
#include <cmath>

__int64 biexp(__int64 a, __int64 b, __int64 mod)
{
	__int64 ret = 1;
	while (b != 0)
	{
		if (b % 2)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ret;
}

char hex_table [] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void DecToHexSingle(unsigned char dec, char * hex)
{
	*hex = hex_table[dec >> 4];
	*(hex + 1) = hex_table[dec & 0x0F];
}

void DecToHexArray(unsigned char dec [], char hex [], int count)
{
	for (int i = 0; i < count; i++)
		DecToHexSingle(dec[i], &hex[2 * i]);
}

void DecToHexModDiv(unsigned char dec, char &hex)
{
	hex = hex_table[dec];
}

double _16dSj(__int64 d, int j)
{
	double sum = 0;
	for (__int64 k = 0; k <= d; k++)
	{
		sum += (double) biexp(16, d - k, 8 * k + j) / (8 * k + j);
	}

	return fmod(sum, 1);
}