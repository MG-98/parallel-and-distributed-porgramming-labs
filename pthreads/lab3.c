#include <pthread.h>
#include <stdio.h>
//#include <stdib.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *Printhello (void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me , thread #%ld\n", tid);

}

int main ()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for ( t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&threads[t],NULL , Printhello , (void*)t);
        
    }
    if (rc)
    {
        printf("ERROR; return code from pthread_creat() is %d\n" , rc);
        exit(-1);
        
    }

    for (long i = 0; i < NUM_THREADS; i++)
        {
            pthread_join(threads[i] , NULL);
        }
    printf("this is Parent!\n");
    
    
    pthread_mutex_t mutexvar;
    pthread_mutex_init(& mutexvar , NULL);
    pthread_mutex_lock(&mutexvar);
    mutexvar = 10;
    pthread_mutex_unlock(&mutexvar);

}

