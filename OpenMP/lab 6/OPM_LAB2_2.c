#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N       50



int main () 
{
int nthreads,tid , tid_1 , tid_2, i, chunk;
float a[N], b[N], sum[N] , mul[N];
 double start_time , run_time;
    clock_t begin, end;
    double CPU_time;


/* Some initializations */
for (i=0; i < N; i++)
  a[i] = b[i] = i * 1.0;
  begin = clock();
#pragma omp parallel 
{
    
    #pragma omp sections nowait
    {
        #pragma omp section
{
    

        for (i=0; i<N; i++)
            {
            sum[i] = a[i] + b[i];
            }
            tid_1 = omp_get_thread_num();
    printf("Thread number sum :  %d " , tid_1 ) ;

}
    #pragma omp section 
{

        for (i=0; i<N; i++)
            {
            mul[i] = a[i] * b[i];
        }
        tid_2 = omp_get_thread_num();
printf("Thread number mul :  %d \n " , tid_2 ) ; 
       }
      
          }
           tid = omp_get_thread_num();
       printf("Thread number out section :  %d \n " , tid ) ; 
}  
end = clock();
   CPU_time = (double)(end - begin) / CLOCKS_PER_SEC;// get processor time
printf("Sum & mul took %f seconds to execute\n", CPU_time);
  /* for (int i=0; i < N; i++)
  {printf("%f \n" ,sum[i]);}
    printf("I am here\n");

  for (int i=0; i < N; i++)
    {printf("%f \n", mul[i]);}*/

}