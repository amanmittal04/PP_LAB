#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int max;
    printf("Enter the number upto which sum is required: ");
    scanf("%d",&max);
    int sum = 0;
    #pragma omp parallel for
    for (int i = 1; i <= max; i++)
        #pragma omp critical
        sum += i;
    
    printf("Sum : %d\n", sum);
    return 0;
}