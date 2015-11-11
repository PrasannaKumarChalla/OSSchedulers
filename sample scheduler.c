//these lines would go in schedulers.h
#include <stdlib.h>
/*
 * \brief: determines what process to allocate the CPU to, randomly
 * \pre numprocs >= 0
 * \pre the procs array has been allocated with at least numprocs spaces
 * \return: the index of a randomly running process
 */
int rand_sched(proc_t * procs, const int numprocs, const int ts);

//This function definition would go in schedulers.c
int rand_sched(proc_t * procs, const int numprocs, const int ts)
{
    int * running_procs = malloc(sizeof(int) * numprocs);
    int numrunning = 0;
    int i;
    int rand_idx;
    int to_run;
    // first, determine which processes are running
    // in other words, which processes have started, but not finished?
    for (i=0; i<numprocs; i++)
    {
        if (running(&procs[i], ts))
        {
            // if the process at index i is running, store the index in the list
            running_procs[numrunning] = i;
            numrunning ++;
        }
    }
    //
    rand_idx = rand() % numrunning;
    //randomly choose one of the indexes of a process that is running
    to_run = running_procs[rand_idx];
    // Don't want any memory leaks
    free(running_procs);
    return to_run;
}

// To run/test this scheduler, add this line in your main():
run_scheduler(processes, numprocs, rand_sched, "RANDOM");

//note, you may want to #include time.h in your main.c, and run srand(time(NULL)) at the top of main so you see random behavior

//I see output that looks somewhat like this:
/*
===== RUNNING RANDOM =====
   == RUN GRAPH ==
A |>B   W   W   W   W   B   W   W   W   W   W   W   B   B   W   W   B   W   W   B   W   W   B   B   W   B   W   B< 
B |        >W   W   W   W   B   W   W   W   B   W   W   W   W   B   W   W   W   W   W   B   W   W   W   W   B<     
C |            >W   W   W   W   W   B<                                                                             
D |                    >W   W   W   W   B<                                                                         
E |    >B   B   B   B   W   W   B   W   W   W   B   W   W   B   W   W   B   B   W   B   W   W   W   B<             
-------------------------------------------------------------------------------------------------------------------
  |000|001|002|003|004|005|006|007|008|009|010|011|012|013|014|015|016|017|018|019|020|021|022|023|024|025|026|027|
-- Stats --
  Avg. Response Time (Avg. Wait): 12.000000
  Avg. Turnaround Time          : 17.600000

*/
// Your output may/will be different based on the random numbers you get from rand()