/*
==================================================================================================================================
Name: 30.c
Author: Anuja Jose
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>


#define TARGET_HOUR 11
#define TARGET_MIN 50


void init_daemon() {
    pid_t pid = fork();

    if (pid < 0) exit(1);     
    if (pid > 0) exit(0);   


    setsid();        
    umask(0);           
    chdir("/");            

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);


}

int main() {
    init_daemon();

 
    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == TARGET_HOUR && t->tm_min == TARGET_MIN)
        {
            system("/home/anuja/Documents/SS/handsonl1/daemon_script.sh");
            sleep(60);
        }
    sleep(60); 
 
    }

    return 0;
}

/*Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cc 30.c -o daemon_runner
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./daemon_runner 
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cat /tmp/daemon_output.log
Current time: Sun 07 Sep 2025 11:50:04 AM IST

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ps aux | grep daemon_runner
anuja       6466  0.0  0.0   2684  1256 ?        Ss   11:50   0:00 ./daemon_runner
anuja       6565  0.0  0.0   6632  2124 pts/1    S+   11:51   0:00 grep --color=auto daemon_runner
*/