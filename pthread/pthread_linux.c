#include<stdio.h>
#include<pthread.h>

#define NUM_OF_THREADS 4

void threadFunction(void *arg){
    long thread_pid=(long) arg;
    printf("Hello from thread %d\n",thread_pid);
    pthread_exit(NULL);
}

int main(){

    pthread_t threads[NUM_OF_THREADS];
    int thread_ids[NUM_OF_THREADS];
    int rc;

    for(int i=0;i<NUM_OF_THREADS;i++){
        thread_ids[i]=i;
        rc=pthread_create(&threads[i],NULL,threadFunction,(void *)&thread_ids[i]);

        if(rc){
            printf("Error: Unable to create thread %ld\n", i);
            return -1;
        }
    }

    // wait for the threads
    for(int i=0;i<NUM_OF_THREADS;i++){
        rc=pthread_join(threads[i],NULL);
        if(rc){
            printf("Error: Unable to join thread %d\n", i);
            return -1;
        }   
    }

    printf("All threads finished\n");

    return 0;
}