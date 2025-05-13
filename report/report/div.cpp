#include "sub.h"

int divide(int x, int y) {
	int cnt = 0;

	for (int i = 0;i < sub(x, y) <= 1;i++) {
		cnt++;
	}

	return cnt;
}