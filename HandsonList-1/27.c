/*
==================================================================================================================================
Name: 27.c
Author: Anuja Jose
Description: Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 30th Aug, 2025
==================================================================================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
pid_t c1,c2,c3,c4;
c1 = fork();  
int state;
if(c1 == 0) 
{
    c2 = fork();
    if(c2==0)
    {
        c3 = fork();
        if(c3==0)
        {

            c4 = fork();
            if(c4==0)
            {
            printf("a)Executing ls -Rl using execl\n");
            execl("/bin/ls", "ls", "-Rl", NULL);
            }
            else
            {
            waitpid(c4,&state,0);
            printf("b)Executing ls -Rl using execlp\n");
            execlp("ls", "ls", "-Rl", NULL);    
            }
        }
        else
        {   
            waitpid(c3,&state,0);
            printf("c)Executing ls -Rl using execle\n");
            char *envp[] = { "PATH=/bin:/usr/bin", NULL };  
            execle("/bin/ls", "ls", "-Rl", NULL, envp);
         
        }
    }
    else

    {    
        waitpid(c2,&state,0);
        printf("\nd)Executing ls -Rl using execv\n");
        char *argv[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", argv); 
    
    }

}
else
{
    waitpid(c1,&state,0);
    printf("e)Executing ls -Rl using execvp\n");
    char *argv[] = {"ls", "-Rl", NULL};
    execvp("ls", argv); 

}
}





/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1/ls_lists$ ./a.out 
a)Executing ls -Rl using execl
.:
total 100
-rw-rw-r-- 1 anuja anuja  1652 Sep  6 19:29 27.c
-rwxrwxr-x 1 anuja anuja 16304 Sep  6 19:31 a.out
-rwxrwxr-x 1 anuja anuja 16040 Sep  6 18:34 filecreation
-rwxrwxr-x 1 anuja anuja 16136 Sep  6 18:31 filetype_detector
-rwxrwxr-x 1 anuja anuja    49 Aug 19 16:00 gg.sh
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 reader
-rw-rw-r-- 1 anuja anuja    39 Aug 22 16:48 source
-rw-rw-r-- 1 anuja anuja  3471 Aug 28 15:15 source.txt
-rw-rw-r-- 1 anuja anuja   273 Aug 22 16:21 test.c
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 writer
b)Executing ls -Rl using execlp
.:
total 100
-rw-rw-r-- 1 anuja anuja  1652 Sep  6 19:29 27.c
-rwxrwxr-x 1 anuja anuja 16304 Sep  6 19:31 a.out
-rwxrwxr-x 1 anuja anuja 16040 Sep  6 18:34 filecreation
-rwxrwxr-x 1 anuja anuja 16136 Sep  6 18:31 filetype_detector
-rwxrwxr-x 1 anuja anuja    49 Aug 19 16:00 gg.sh
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 reader
-rw-rw-r-- 1 anuja anuja    39 Aug 22 16:48 source
-rw-rw-r-- 1 anuja anuja  3471 Aug 28 15:15 source.txt
-rw-rw-r-- 1 anuja anuja   273 Aug 22 16:21 test.c
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 writer
c)Executing ls -Rl using execle
.:
total 100
-rw-rw-r-- 1 anuja anuja  1652 Sep  6 19:29 27.c
-rwxrwxr-x 1 anuja anuja 16304 Sep  6 19:31 a.out
-rwxrwxr-x 1 anuja anuja 16040 Sep  6 18:34 filecreation
-rwxrwxr-x 1 anuja anuja 16136 Sep  6 18:31 filetype_detector
-rwxrwxr-x 1 anuja anuja    49 Aug 19 16:00 gg.sh
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 reader
-rw-rw-r-- 1 anuja anuja    39 Aug 22 16:48 source
-rw-rw-r-- 1 anuja anuja  3471 Aug 28 15:15 source.txt
-rw-rw-r-- 1 anuja anuja   273 Aug 22 16:21 test.c
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 writer

d)Executing ls -Rl using execv
.:
total 100
-rw-rw-r-- 1 anuja anuja  1652 Sep  6 19:29 27.c
-rwxrwxr-x 1 anuja anuja 16304 Sep  6 19:31 a.out
-rwxrwxr-x 1 anuja anuja 16040 Sep  6 18:34 filecreation
-rwxrwxr-x 1 anuja anuja 16136 Sep  6 18:31 filetype_detector
-rwxrwxr-x 1 anuja anuja    49 Aug 19 16:00 gg.sh
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 reader
-rw-rw-r-- 1 anuja anuja    39 Aug 22 16:48 source
-rw-rw-r-- 1 anuja anuja  3471 Aug 28 15:15 source.txt
-rw-rw-r-- 1 anuja anuja   273 Aug 22 16:21 test.c
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 writer
e)Executing ls -Rl using execvp
.:
total 100
-rw-rw-r-- 1 anuja anuja  1652 Sep  6 19:29 27.c
-rwxrwxr-x 1 anuja anuja 16304 Sep  6 19:31 a.out
-rwxrwxr-x 1 anuja anuja 16040 Sep  6 18:34 filecreation
-rwxrwxr-x 1 anuja anuja 16136 Sep  6 18:31 filetype_detector
-rwxrwxr-x 1 anuja anuja    49 Aug 19 16:00 gg.sh
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 reader
-rw-rw-r-- 1 anuja anuja    39 Aug 22 16:48 source
-rw-rw-r-- 1 anuja anuja  3471 Aug 28 15:15 source.txt
-rw-rw-r-- 1 anuja anuja   273 Aug 22 16:21 test.c
-rwxrwxr-x 1 anuja anuja 16224 Sep  6 12:24 writer
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1/ls_lists$ 
*/
