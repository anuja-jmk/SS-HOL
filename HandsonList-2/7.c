/*
==================================================================================================================================
Name: 7.c
Author: Anuja Jose
Description: Write a simple program to print the created thread ids.
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
Thread id is 132990139102912
Thread id is 132990130710208
Thread id is 132990122317504
anuja@anuja-Precision-5550

*/