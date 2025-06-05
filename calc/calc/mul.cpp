#include "add.h"

int mul(int x, int y)
{
	int num = 0;

	for (int i = 0; i < y; i++)
	{
		num = add(num, x);
	}

	return num;
}