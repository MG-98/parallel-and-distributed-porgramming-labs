#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

static long num_steps = 100000; 
double step;
#define NUM_THREADS 10


void main ()
{
 int nthreads; 
 double pi;

 step = 1.0/(double) num_steps;

 omp_set_num_threads(NUM_THREADS);

 #pragma omp parallel
 {

 int i, id, nthrds;
 double x , sum;
 
 id = omp_get_thread_num();
 nthrds = omp_get_num_threads();

 if (id == 0) nthreads = nthrds;
sum =0;
 for (i=id; i< num_steps;  i=i+nthrds) 
 {
 x = (i+0.5)*step;
 sum += 4.0/(1.0+x*x);
 }
#pragma omp critical
 pi += sum * step;
 }
 
 printf("Pi = %f \n" , pi);

}