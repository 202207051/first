#include <iostream>
#include "add.h"        
#include "mul.h"
#include "sub.h"
#include "div.h"
#include "mol.h"

int main() {
    int x = 12;
    int y = 5;
    printf("add - %d\n", add(x, y));
    printf("mul - %d\n", mul(x, y));
    printf("sub - %d\n", sub(x, y));
    printf("div - %d\n", div(x, y));
    printf("mol - %d\n", mol(x, y));
}