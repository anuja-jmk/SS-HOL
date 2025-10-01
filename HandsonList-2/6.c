/*
==================================================================================================================================
Name: 6.c
Author: Anuja Jose
Description: Write a simple program to create three threads.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void thread_func(void)
{
    printf("Thread id is %ld\n",pthread_self());
}
void main()
{
    pthread_t mythreads[3];

    for ( int i = 0; i < 3; i++)
    {
    pthread_create(&mythreads[i], NULL, (void *) thread_func, NULL);
    }


    for (int i = 0; i < 3; i++) {
        pthread_join(mythreads[i], NULL);
    }
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Thread id is 133802229757632
Thread id is 133802221364928
Thread id is 133802212972224
anuja@anuja-Precision-5550:~/

*/