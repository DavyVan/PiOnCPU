#include "functions.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <Windows.h>

#define dLEAP 2
#define PRECISION_INIT 2
#define PRECISION_HEX 10000	//of digits in hex
#define PRECISION_OUTPUT_START 100
#define PRECISION_OUTPUT_END 100

#define _ALL_

unsigned char result_dec[PRECISION_HEX] = { 0 };
char result_hex[PRECISION_HEX + 1] = { 0 };

int main()
{
	assert(PRECISION_OUTPUT_START < PRECISION_HEX && PRECISION_OUTPUT_END <= PRECISION_HEX);
	printf("Start to compute Pi...\n");
	time_t elapseTime, startTime, endTime;
	startTime = time(NULL);
#ifdef _ALL_
	__int64 precision_current = PRECISION_INIT;
	double _16dPi = 0;
	for (; precision_current < PRECISION_HEX; precision_current += dLEAP)
	{
		if (precision_current % 100 == 0)
			printf(".");

		_16dPi = 4 * _16dSj(precision_current, 1) - 2 * _16dSj(precision_current, 4) - _16dSj(precision_current, 5) - _16dSj(precision_current, 6);
		_16dPi = fmod(_16dPi + ceil(abs(_16dPi)), 1);

		for (__int64 i = precision_current; i < precision_current + dLEAP; i++)
		{
			_16dPi *= 16;
			result_dec[i] = floor(_16dPi);
			_16dPi -= result_dec[i];

			DecToHexModDiv(result_dec[i], result_hex[i]);
		}
	}
	printf("\n");

	for (__int64 i = PRECISION_OUTPUT_START; i < PRECISION_OUTPUT_END; i++)
	{
		printf("%c", result_hex[i]);
	}
	printf("\n");
#else
	double _16dPi = 4 * _16dSj(PRECISION_HEX, 1) - 2 * _16dSj(PRECISION_HEX, 4) - _16dSj(PRECISION_HEX, 5) - _16dSj(PRECISION_HEX, 6);
	_16dPi = fmod(_16dPi+1, 1);

	for (__int64 i = 0; i < dLEAP; i++)
	{
		_16dPi *= 16;
		result_dec[i] = floor(_16dPi);
		_16dPi -= result_dec[i];

		DecToHexModDiv(result_dec[i], result_hex[i]);
		printf("%c", result_hex[i]);
	}
	printf("\n");
#endif
	endTime = time(NULL);
	elapseTime = endTime - startTime;
	printf("Total Time: %I64d\n", elapseTime);
}