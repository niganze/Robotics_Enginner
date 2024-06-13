#include <stdio.h>

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int value1 = 35;
    int value2 = -97;


    printf("Before swap: value1 = %d, value2 = %d\n", value1, value2);

    
    swapValues(&value1, &value2);

    
    printf("After swap: value1 = %d, value2 = %d\n", value1, value2);

    return 0;
}