/*
==================================================================================================================================
Name: 2.c
Author: Anuja Jose
Description: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 30th Aug, 2025
==================================================================================================================================
*/



#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main()
{
    int k;
    pid_t pr_id;
    pr_id=getpid();
    for(k=-1; k<0;k--)
        {printf("    Running infinite loop..\nPID: %d",pr_id);
            sleep(2);
        }


}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
    Running infinite loop..
PID: 15555    Running infinite loop..
PID: 15555    Running infinite loop..
PID: 15555    Running infinite loop..
PID: 15555    Running infinite loop..
PID: 15555    Running infinite loop..
PID: 15555    Running infinite loop..
PID: 15555    Running infinite loop

anuja@anuja-Precision-5550:~$ cat /proc/15555/status
Name:   a.out
Umask:  0002
State:  S (sleeping)
Tgid:   15555
Ngid:   0
Pid:    15555
PPid:   9622
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 100 114 1000 
NStgid: 15555
NSpid:  15555
NSpgid: 15555
NSsid:  9622
Kthread:        0
VmPeak:     2684 kB
VmSize:     2684 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:      1500 kB
VmRSS:      1500 kB
RssAnon:               0 kB
RssFile:            1500 kB
RssShmem:              0 kB
VmData:      224 kB
VmStk:       136 kB
VmExe:         4 kB
VmLib:      1748 kB
VmPTE:        48 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
untag_mask:     0xffffffffffffffff
Threads:        1
SigQ:   0/126557
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000000
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   ffff
Cpus_allowed_list:      0-15
Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:      0
voluntary_ctxt_switches:        11
nonvoluntary_ctxt_switches:     0
x86_Thread_features:
x86_Thread_features_locked:
*/