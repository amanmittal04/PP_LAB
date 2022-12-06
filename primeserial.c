#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int j=0,primes[20],x = 3;

int isPrime(int x){
	for(int i=2;i<x/2;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main(){
    double start = omp_get_wtime();
	while(j<20){
		if(isPrime(x))
		{	primes[j]=x;
			j++;
		}	
		x+=2;
	}	
    double end = omp_get_wtime();
	for(int i=0;i<20;i++) printf("%d ",primes[i]);
    printf("\n");
    double val = end - start;
	printf("\nTime for serial execution is:%f\n",val);
    return 0;
}

