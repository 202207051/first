#include <iostream>
#include <stdio.h>
#include <time.h>

int getlotto() {
	int num = 0;
	num = rand() % 45 + 1;
	return num;
}

int checklotto(int* lotto, int* i) {
	int flag = 0;

	for (int j = 0;j < *i; j++) {
		if (lotto[*i] == lotto[j]) {
			flag = 1;
			break;
		}
	}

	return flag;
}

void sortlotto(int *lotto) {
	int k, l;
	int temp;
	for (int k = 0;k < 5;k++) {
		for (int l = k + 1;l < 6;l++) {
			if (lotto[k] > lotto[l]) {
				temp = lotto[k];
				lotto[k] = lotto[l];
				lotto[l] = temp;
			}
		}
	}
}

int main()
{
	int lotto[6] = { 0 };
	int i, j;
	int flag;

	srand(time(NULL));

	for (i = 0; i < 6; i++) {
		lotto[i] = getlotto();
		do {
			flag = checklotto(lotto, &i);
		} while (flag);
	}

	sortlotto(lotto);

	for (j = 0; j < 6; j++) {
		printf("%d ", lotto[j]);
	}
}