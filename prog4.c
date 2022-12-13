#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


void main(int argc,char *argv[]){
  int rank,size,n,root=0;
  printf("Enter the number whose Factorial you want: ");
  scanf("%d",&n);
  int global,localProd=1;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
  int len = (n/size) + 1;
  for(int i=1;i<=len;i++){
    printf("\nRank:%d Len:%d N:%d Itern:%d",rank,len,n,i);
    int val = (rank*len) + i;
    printf("\nRank:%d Value:%d",rank,val);
    if(val<=n) localProd *= val;
    else break;
  }
  printf("\nLocal Product: %d",localProd);
  MPI_Reduce(&localProd,&global,1,MPI_INT,MPI_PROD,root,MPI_COMM_WORLD);
  printf("\nFactorial of %d is %d\n",n,global);
  
  MPI_Finalize();
}