#include <iostream>

int mul(int, int);
int add(int, int);

int main()
{
	int a = 4;
	int b = 2;
	int result;

	result = mul(a, b);

	printf("mul : %d\n", result);
}
int mul(int a, int b)
{
	int sum = 0;

	for (int i = 0; i < b; i++)
	{
		sum = add(sum, a);
	}

	return sum;
}

int add(int a, int b)
{
	return a + b;
}