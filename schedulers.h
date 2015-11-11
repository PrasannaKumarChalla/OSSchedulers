#ifndef SOLN_SCHEDULERS_H
#define SOLN_SCHEDULERS_H

#include "proc.h"
#include "cpu_sched.h"

int fcfs(proc_t * processes, int numprocesses, int timeslice);
int srt(proc_t * processes, int numprocesses, int timeslice);
int sjf(proc_t * processes, int numprocesses, int timeslice);
// int srt(proc_t * processes, int numprocesses, int timeslice);
// int rr(proc_t * processes, int numprocesses, int timeslice);
#endif //SOLN_SCHEDULERS_H
