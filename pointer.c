#include <stdio.h>

int main() {
    int x = 10;
    int *p, *q;

    p = &x;
    q = &x;

    printf("Initial value of x: %d\n", x);

    *p = 20;
    
    printf("Value of x after changing via p: %d\n", *q);

    return 0;
}