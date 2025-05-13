#include <iostream>
#include "add.h"        
#include "mul.h"
#include "sub.h"
#include "div.h"
#include "mol.h"

int main() {
    int x = 17;
    int y = 2;
    printf("add - %d\n", add(x, y));
    printf("mul - %d\n", mul(x, y));
    printf("sub - %d\n", sub(x, y));
    printf("div - %d\n", divide(x, y));
    printf("mol - %d\n", mol(x, y));
}