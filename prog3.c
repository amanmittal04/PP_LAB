#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc,char *argv[]){
  int n=10;
  int a[n],b[n],c[n];
  printf("\nA's array: ");
  for(int i=0;i<n;i++){
    a[i] = rand()%10;
    printf("%d ",a[i]);
  }
  printf("\nB's array: ");
   for(int i=0;i<n;i++){
    b[i] = rand()%10;
    printf("%d ",b[i]);
  } 
    printf("\n");
  int rank,size,root=0;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int subsize = n/size;
    int *ap = malloc(sizeof(int)*subsize);
    int *bp = malloc(sizeof(int)*subsize);
    int *cp = malloc(sizeof(int)*subsize);

    MPI_Scatter(a,subsize,MPI_INT,ap,subsize,MPI_INT,root,MPI_COMM_WORLD);
    MPI_Scatter(b,subsize,MPI_INT,bp,subsize,MPI_INT,root,MPI_COMM_WORLD);

    for(int i=0;i<subsize;i++){
      cp[i] = ap[i] + bp[i];
    }

  MPI_Gather(cp,subsize,MPI_INT,c,subsize,MPI_INT,root,MPI_COMM_WORLD);
    if(rank==root){
      printf("\nResultant Array: ");
      for(int i=0;i<n;i++) printf("%d ",c[i]);
      printf("\n");
    }
  MPI_Finalize();
}