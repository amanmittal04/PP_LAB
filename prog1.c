#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc,char *argv[]){
  char outmssg[100] = "I Love You!";
  char inmssg[100];
  int rank,size,dest,source,rc,count,tag=1;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Status stat;
  if(rank==0){
    dest=1;
    rc = MPI_Send(&outmssg,strlen(outmssg),MPI_CHAR,dest,tag,MPI_COMM_WORLD);
  }else if(rank==1){
    source=0;
    rc = MPI_Recv(&inmssg,strlen(outmssg),MPI_CHAR,source,tag,MPI_COMM_WORLD,&stat);
  }
  rc = MPI_Get_count(&stat,MPI_CHAR,&count);
  printf("Task %d recieved %d characters from Source %d with Tag %d and message is %s\n",rank,count,stat.MPI_SOURCE,stat.MPI_TAG,inmssg);
  MPI_Finalize();
}