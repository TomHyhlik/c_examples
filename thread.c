/*
 * compile with gcc -pthread 
 */

#include <stdio.h> 
#include <stdlib.h> 

 /* Header file for sleep(). man 3 sleep for details. */
#include <unistd.h> 
#include <pthread.h> 
  
/* function that is executed as a thread when its name is specified in pthread_create() */
void* myThreadFun(void *vargp) 
{ 
    printf("Started %s\n", __func__);
    uint32_t ctr = 0;

	while (1)
	{
	    printf("Running: %u \n", ctr++); 
        sleep(1); 
	}
} 
   
int main() 
{ 
    printf("AppStart...........................\n"); 

    pthread_t thread_id; 
    pthread_create(&thread_id, NULL, myThreadFun, NULL); 
    // pthread_join(thread_id, NULL); 


    while(1)
    {

    }

    exit(0); 
}