#include <iostream>
#include "add.h"
#include "dive.h"
#include "mod.h"
#include "mul.h"
#include "sub.h"



int main()
{
	int x = 0;
	int y = 0;

	std::cout << "ù��° ���� �Է��ϼ��� : ";
	std::cin >> x;
	std::cout << "�ι�° ���� �Է��ϼ���";
	std::cin >> y;

	printf("�Էµ� �� x[ %d ] y[ %d ]\n", x, y);
	printf("add[ %d ] sub[ %d ] mul[ %d ] dive[ %d ] mod[ %d ]\n",
		add(x, y), sub(x, y), mul(x, y), dive(x, y), mod(x, y));
}