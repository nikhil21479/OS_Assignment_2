#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


void *pA(){
  for(long long int i = 0; i<4294967296; i++){   
  }
}
void *pB(){
  for(long long int i = 0; i<4294967296; i++){
  }
}
void *pC(){
  for(long long int i = 0; i<4294967296; i++){
  }
}


int main(){
  struct sched_param param;
	pthread_t thr1, thr2, thr3;
  double a1,a2,a3,a4,a5,a6,a7,a8,a9;
  clock_t b1,b2,b3,b4,b5,b6,b7,b8,b9,c1,c2,c3,c4,c5,c6,c7,c8,c9;
  
  FILE * filename;
  filename = fopen("data.txt","w");
  b1=clock();
  pthread_create(&thr1, NULL, pA, NULL);
  pthread_create(&thr1, NULL, pB, NULL);
  pthread_create(&thr1, NULL, pC, NULL);
  pthread_setschedparam(thr1, SCHED_OTHER, &param);
  pthread_join(thr1, NULL);
  
  c1=clock();
  a1=(double)(c1-b1);
  printf("Time for thread 1: %f\n",a1/3000000);
  fprintf(filename," %f\n",a1/3000000);
  for(int i = 1; i<=4; i++){
    printf("For Priority: %d ",i);
    b2=clock();
    pthread_setschedprio(thr1,i);
    pthread_join(thr1, NULL);
    c2=clock();
    a2=(double)(c2-b2);
    printf("Time for thread 1: %f\n",a2/1000000);
    fprintf(filename," %f\n",a2/1000000);
  }
  b3=clock();
  pthread_create(&thr2, NULL, pA, NULL);
  pthread_create(&thr2, NULL, pB, NULL);
  pthread_create(&thr2, NULL, pC, NULL);
  pthread_setschedparam(thr2, SCHED_RR, &param);
  pthread_join(thr2, NULL);
  c3=clock();
  a3=(double) (c3-b3);
  printf("Time for thread 2: %f\n",a3/3000000);
  fprintf(filename,"%f\n",a3/3000000);
  for(int i = 1; i<=4; i++){
    printf("For Priority: %d ",i);
    b4=clock();
    pthread_setschedprio(thr2,i);
    pthread_join(thr2, NULL);
    c4=clock();
    a4=(double)(c4-a4);
    printf("Time for thread 2: %f\n",a4/1000000);
    fprintf(filename,"%f\n",a4/1000000);  
  }
  b5=clock();
  pthread_create(&thr3, NULL, pA, NULL);
  pthread_create(&thr3, NULL, pB, NULL);
  pthread_create(&thr3, NULL, pC, NULL);
  pthread_setschedparam(thr3, SCHED_FIFO, &param);
  pthread_join(thr3, NULL);
  c5=clock();
  a5=(double)(c5-b5);
  printf("Time for thread 3: %f\n",a5/3000000);
  fprintf(filename," %f\n",a5/3000000);

  for(int i = 1; i<=4; i++){
    printf("For Priority: %d ",i);
    b6=clock();
    pthread_setschedprio(thr3,i);
    pthread_join(thr3, NULL);
    c6=clock();
    a6=(double)(c6-b6);
    printf("Time for thread3: %f\n",a6/1000000);
    fprintf(filename,"%f\n",a6/1000000); 
  }
  fclose(filename);
	exit(0);
}
