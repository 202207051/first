#include "sub.h"

int mol(int x, int y) {
	int num = x;
	int cnt = 0;

	while (num >= y) {
		num = sub(num, y);
		cnt++;
	}

	return num;
}