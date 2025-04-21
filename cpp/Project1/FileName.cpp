#include <iostream>

int main() {
	int a = 3;
	int* p = &a;

	printf("a - %d *p - %d\n", a, *p);

	*p = 5;
	printf("a - %d *p - %d", a, *p);
}