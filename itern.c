#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    int iterns=8,itern=1;
    #pragma omp parallel for schedule(static,2)
    for(int i=1; i<=iterns; i++){
        int t = omp_get_thread_num();
        itern+=1;
        itern%=2;
        printf("thread %d itern %d value: %d\n",t,itern+1,i);
    }
}
