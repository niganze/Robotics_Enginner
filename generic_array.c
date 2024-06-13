#include <stdio.h>


double summarize(double *array, int num_values) {
    double sum = 0.0;
    for (int i = 0; i < num_values; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    
    double values[5] = {1.0, 2.5, 3.5, 4.0, 5.5};

    
    int num_values = 3;

    
    double result = summarize(values, num_values);
    printf("The sum of the first %d values is: %.2f\n", num_values, result);

    return 0;
}
