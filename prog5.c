#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int isPrime(int x){
  if(x==0 || x==1) return 0;
  if(x==2 || x==3) return 1;
  for(int i=2;i<=x/2;i++){
    if(x%i==0) return 0;
  }
  return 1;
}
void main(int argc,char *argv[]){
  int rank,size,n,root=0;
  printf("Enter the number: ");
  scanf("%d",&n);
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
  int *globalData = malloc(n*sizeof(int));
  int itern = (n/size) + 1;
  for(int i=0;i<n;i++){
    globalData[i] = i+1;
  }
  printf("Rank:%d Size:%d Itern:%d N:%d\n",rank,size,itern,n);
  for(int i=(rank*itern);i<((rank+1)*itern);i++){
    if(i>n) break;
    if(isPrime(globalData[i])){
      printf("%d ",globalData[i]);
    }
  }
  printf("\n");
  MPI_Finalize();
}