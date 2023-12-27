/* Edison Zhang */

#include <stdio.h>
#include "include.h"
#include "lab1.h"

int foo(int x)
{ return 2* x; }

int mult_two(int x)
{
    return 2* x;
}

int main()
{
    int i = INIT, j;

    printf("Before, i=%d\n", i);
    j = mult_two(i);
    printf("After, j=%d\n", j);
    /* Returning 0 to the system signifies no erros */
    return 0;
}

