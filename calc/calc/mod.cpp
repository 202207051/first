#include "sub.h"

int mod(int x, int y)
{

	int num = x;

	while (num >= y)
	{
		num = sub(num, y);
	}

	return num;
}