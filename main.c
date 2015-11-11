/*
 * \file main.c
 * \author Nathan Eloe
 * \brief runs the simulations of different CPU scheduler policies
 * Modified by:
 */

#include "proc.h"
#include "cpu_sched.h"
#include "schedulers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    proc_t * processes;
    FILE * procfile;
    int numprocs;
    int i;
    if (argc != 2)
    {
        printf("You must specify a file containing the process descriptions");
        exit(1);
    }
    procfile = fopen(argv[1], "r");
    if (!procfile)
    {
        printf("Cannot open file %s for reading; exiting", argv[1]);
        exit(1);
    }

    // printf("Testing queue------\n");
    InitQueue();
    // printf("Q created\n");
    // Enqueue(5);
    // Enqueue(7);
    // printf("Enqueue doene\n");
    // printf("Checking queue is full or empty\n");
    // printf("Is Empty:%d\n",isEmpty());
    // printf("Is Full:%d\n",isFull());
    // printf("Deq number is %d\n",Dequeue());
    // printf("Done\n");



    fscanf(procfile, "%d\n", &numprocs);

    processes = calloc(numprocs, sizeof(proc_t));
    for (i=0; i<numprocs; i++)
    {
        fscanf(procfile, "%c %d %d\n", &(processes[i].m_procname), &(processes[i].m_burst),
                                     &(processes[i].m_arrive));
    }
    fclose(procfile);
    for (i=0; i<numprocs; i++){
        print_process(&processes[i]);
    }
 //run_scheduler(processes, numprocs, rand_sched, "RANDOM");
   run_scheduler(processes, numprocs, fcfs, "FCFS");
    run_scheduler(processes, numprocs, sjf, "SJF");
    run_scheduler(processes, numprocs, srt, "SRT");
    run_scheduler(processes, numprocs, rr, "RR");
    //reset_all frees the memory the processes take (since they have a LL of nodes...)
    reset_all(processes, numprocs);
    free(processes);
    return 0;
}
