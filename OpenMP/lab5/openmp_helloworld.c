#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int nthreads, tid, i, chunk;
    printf("  Hello world outside the programme\n");
    #pragma omp parallel 
    {
  
  printf("Hello world Thread %d starting...\n");
    
    }
}