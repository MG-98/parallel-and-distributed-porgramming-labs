#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <pthread.h>




static long num_steps =  100000000;
double step ;

int main()
{
    int i ;
    double x , pi , mysum = 0.0 , sum =0.0;
    double start_time , run_time;
    clock_t begin, end;
double CPU_time;

    step = 1.0 / (double)num_steps;
     begin = clock();
    
    #pragma omp parallel private (mysum , x)
    {
//#pragma omp parallel for reduction (+: sum) 
// #pragma omp parallel for 
    for (int i = 1; i < num_steps; i++)
   // #pragma omp critical
    {
      x =  (i-0.5)*step;
      mysum = mysum + (4.0/(1.0+(x*x)));
     #pragma omp atomic
     sum = sum + mysum;
       // sum = sum + (4.0/(1.0+(x*x)));
    }
    }
end = clock();
   CPU_time = (double)(end - begin) / CLOCKS_PER_SEC;// get processor time
printf("PI calculations took %f mil seconds to execute\n", CPU_time);
    pi = step*sum;
    printf("%f \n" , pi);
    
}