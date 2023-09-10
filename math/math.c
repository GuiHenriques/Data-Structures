#include <stdio.h>
#include "functions.h"

int main()
{
    int r1 = add(5, 3);
    printf("Result: %i\n", r1);

    int r2 = mult(5, 3);
    printf("Result: %i\n", r2);

    return 0;
}