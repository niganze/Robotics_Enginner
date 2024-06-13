#include <stdio.h>
#define SUCCESS 0
#define NULL_POINTER_ERROR 1

int arrayAdd(double *array, int num_values, double *result) {
    
    if (array == NULL || result == NULL) {
        return NULL_POINTER_ERROR;
    }
    
    double sum = 0.0;
    for (int i = 0; i < num_values; i++) {
        sum += array[i];
    }
    
    *result = sum;
    
    return SUCCESS;
}

int main() {
    
    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int num_values = 3;
    double result;
    int status = arrayAdd(values, num_values, &result);
    if (status == SUCCESS) {
        printf("The sum of the first %d values is: %.2f\n", num_values, result);
    } else if (status == NULL_POINTER_ERROR) {
        printf("Error: NULL pointer passed to arrayAdd function.\n");
    }
    
    return 0;
}