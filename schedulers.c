#include "schedulers.h"
#include "proc.h"
#include "cpu_sched.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fcfs(proc_t * processes, int numprocesses, int timeslice){
int i,to_run,flag=1,arrived;
for(i=0;i<numprocesses;i++){
	if(running(&processes[i],timeslice)){
		    if(flag==1){
		    	arrived=processes[i].m_arrive;
		    	flag=0;
		    }
		    if(arrived>=processes[i].m_arrive){
		    	arrived=processes[i].m_arrive;
		    	to_run=i;
		    }
	}

}
return to_run;
}


int srt(proc_t * processes, int numprocesses, int timeslice){
int i,to_run,flag=1,srt,remainingTime;
for(i=0;i<numprocesses;i++){
	if(running(&processes[i],timeslice)){
            remainingTime=processes[i].m_burst-processes[i].m_timeburst;
		    if(flag==1){
		    	srt=remainingTime;
		    	flag=0;
		    }
		    if(srt>=remainingTime){
		    	srt=remainingTime;
		    	to_run=i;
		    }
	}

}
return to_run;
}

int sjf(proc_t * processes, int numprocesses, int timeslice){
int i,to_run,flag=1,shortestJob;
for(i=0;i<numprocesses;i++){
	//printf("burst time of %d is %d\n",i,processes[i].m_burst);
	if(running(&processes[i],timeslice)){
		    if(processes[i].m_timeburst>0){
                return i;
		    }
		    if(flag==1){
		    	shortestJob=processes[i].m_burst;
		    	flag=0;
		    }
		    if(shortestJob>=processes[i].m_burst){
		    	shortestJob=processes[i].m_burst;
		    	to_run=i;
		    }
	}

}
return to_run;
}


