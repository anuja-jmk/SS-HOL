/*
==================================================================================================================================
Name: 5.c
Author: Anuja Jose
Description: Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main(void){

    int fd;
    pid_t pid;
    char filename[10];
    for(int i=0;i<5;i++)
    {   sprintf(filename,"file%d.txt",i+1);

        fd = open(filename,O_CREAT | O_EXCL | O_RDWR, 0744);
        if(fd<0)
            printf("\nError occured in file creation! fd: %d",fd);
        else
        
            printf("File %s created with file pointer %d.\n",filename,fd);

        close(fd);
    }
    pid = getpid();
    printf("Process Id: %d\n",pid);
    for (int i=0;i<=0;i--)
      {  printf("Hi\n");
            sleep(1);
      }
        

}

/*
Output:


anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
File file1.txt created with file pointer 3.
File file2.txt created with file pointer 4.
File file3.txt created with file pointer 5.
File file4.txt created with file pointer 6.
File file5.txt created with file pointer 7.
Process Id: 47337
Hi
Hi
Hi
Hi
\\

anuja@anuja-Precision-5550:~$ cd /proc/47337/fd
anuja@anuja-Precision-5550:/proc/47337/fd$ ls -l
total 0
lrwx------ 1 anuja anuja 64 Aug 22 18:01 0 -> /dev/pts/3
lrwx------ 1 anuja anuja 64 Aug 22 18:01 1 -> /dev/pts/3
lr-x------ 1 anuja anuja 64 Aug 22 18:01 103 -> /snap/code/200/usr/share/code/v8_context_snapshot.bin
lrwx------ 1 anuja anuja 64 Aug 22 18:01 2 -> /dev/pts/3
lrwx------ 1 anuja anuja 64 Aug 22 18:01 3 -> /home/anuja/Documents/SS/handsonl1/file1.txt
lrwx------ 1 anuja anuja 64 Aug 22 18:01 4 -> /home/anuja/Documents/SS/handsonl1/file2.txt
l-wx------ 1 anuja anuja 64 Aug 22 18:01 41 -> /home/anuja/.config/Code/logs/20250822T101807/ptyhost.log
lrwx------ 1 anuja anuja 64 Aug 22 18:01 42 -> /dev/ptmx
lrwx------ 1 anuja anuja 64 Aug 22 18:01 43 -> /dev/ptmx
lrwx------ 1 anuja anuja 64 Aug 22 18:01 44 -> /dev/ptmx
lrwx------ 1 anuja anuja 64 Aug 22 18:01 5 -> /home/anuja/Documents/SS/handsonl1/file3.txt
lrwx------ 1 anuja anuja 64 Aug 22 18:01 6 -> /home/anuja/Documents/SS/handsonl1/file4.txt
lrwx------ 1 anuja anuja 64 Aug 22 18:01 7 -> /home/anuja/Documents/SS/handsonl1/file5.txt
*/