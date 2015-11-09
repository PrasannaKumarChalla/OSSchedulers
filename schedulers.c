#include "schedulers.h"
#include "proc.h"
#include "cpu_sched.h"
#include <stdio.h>
#include <stdlib.h>
int fcfs(proc_t * processes, int numprocesses, int timeslice){
int i=0,firstArrived=processes[0].m_arrive,result=0;
while(i<numprocesses){
   if(firstArrived>processes[i].m_arrive){
      firstArrived=processes[i].m_arrive;
      result=i;
   }
}
return result;
}
// int fcfs(proc_t * processes, int numprocesses, int timeslice){
// 	return 0;
// }
