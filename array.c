#include <stdio.h>

int main() {

 int array[5] = {19, 28, 83, 94, 115};


int *ptr = &array[4];


 while (ptr >= array) {
        printf("%d\n", *ptr);
        ptr--;
    }
return 0;
}