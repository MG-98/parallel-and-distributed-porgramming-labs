#include <pthread.h>
#include <stdio.h>
//#include <stdib.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define N  1000000

int sum = 0;


struct thread_data
{
   long thread_id;
   int *arr;
   //char *message;
};

struct thread_data thread_data_array[NUM_THREADS];



void *accumlate_sum (void *thready)
{
    int mysum = 0 ;
    struct thread_data *my_data;
    my_data = (struct thread_data *) thready;



    long thready_id  = my_data->thread_id;
    int *my_arr = my_data->arr;

    int ele_per_thread = N / NUM_THREADS;
    int mystart = thready_id * ele_per_thread;
    int myend = (thready_id+1) * ele_per_thread;

    


    printf("my start %d\n", mystart);

    printf("myend %d\n", myend);

    for (int i = mystart; i <myend ; i++)
    {
        mysum = mysum + my_arr[i];
       
    }
    printf("mysum %d\n", mysum);

    pthread_mutex_t mutexvar;
    pthread_mutex_init(& mutexvar , NULL);
    pthread_mutex_lock(&mutexvar);
    sum = sum + mysum;
    pthread_mutex_unlock(&mutexvar);
    pthread_mutex_destroy(&mutexvar);
    



}



/*pthread_mutex_t mutexvar;
    pthread_mutex_init(& mutexvar , NULL);
    pthread_mutex_lock(&mutexvar);
    f
    pthread_mutex_unlock(&mutexvar);*/


int main()
{
    

    int x[N] ;
    for (int i = 0; i < N ; i++){ 
        x[i] = 1; 
    } 

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;


    for ( t = 0; t < NUM_THREADS; t++)
    {
        thread_data_array[t].thread_id = t;
        thread_data_array[t].arr = x;

        rc = pthread_create(&threads[t],NULL , accumlate_sum , (void*)&thread_data_array[t]);
        printf("hi\n");

        
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
    
    printf("SUM %d\n", sum);
   


}