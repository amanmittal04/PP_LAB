#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

double *vectAdd(double *c, double *a, double *b, int n){
    #pragma omp parallel for
    for(int i = 0; i < n; i++){
        c[i] = a[i] + b[i];
    }
    // Return the updated final array
    return c;
}

int main(){
    int n = 10;
    // Create three arrays
    double a[20], b[20], c[20];

    for (int i = 0; i < n; i++){
        // Assign random values
        a[i] = rand() % n;
        b[i] = rand() % n;
    }
    printf("First array elements: ");
    for(int i=0;i<n;i++){
        printf("%f ",a[i]);
    }
    printf("\n");
    printf("Second array elements: ");
    for(int i=0;i<n;i++){
        printf("%f ",b[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++){
        // Print the summations
        printf("%f ", vectAdd(c,a,b,n)[i]);
    }
    return 0;
}