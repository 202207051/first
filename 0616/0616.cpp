#include <iostream>

typedef struct stag
{
	int m;
} stype;

int main()
{
	stag s;
	stype* ps = &s;
	stype s1;
	
	s.m = 11;
	printf("s -> %d\n", s.m);
	printf("ps -> %d\n", ps->m);

	ps->m = 22;
	printf("s -> %d\n", s.m);
	printf("ps -> %d\n", ps->m);

	s1.m = 33;
	stype* ps1 = &s1;
	printf("s -> %d\n", s1.m);
	printf("ps -> %d\n", ps1->m);
}