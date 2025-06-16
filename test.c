<<<<<<< HEAD
#include <iostream>
=======
#include <stdio.h>
>>>>>>> 8cd6f9554bdfe6189c9db623bed6a9095336d269

int main()
{
    int num = 1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", num);
            num++;
        }
        printf("\n");
    }
}