#include <iostream>
#include "ccalc.h"

int main()
{
    ccalc a;
    ccalc b;

    a.m_value = 1;
    b.m_value = 2;

    ccalc sum1 = 1 + 2;
    ccalc sum2 = a + 2;
    ccalc sum3 = 1 + b;
    ccalc sum4 = a + b;
}
