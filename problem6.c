/* 
 * FCFS (First-Come, First-Served) Scheduling Algorithm
 * - It is a algorithm in which the process that arrives first will get the CPU first.
 *   Processes are executed in the order of their arrival.
 * - It folows Non-preemptive algorithm, it means when process gets the CPU, it will
 * run until finishes.
 */

 /* 
  * Pros and Cons
  * Pros:
  *     - Easy to implement
  *     - Fair because processes are served in arrival order.
  *     - No starvation: No tasks will be postponed indefinitely.
  * Cons:
  *     - waiting time is often quite long.
  *     - Not suitable for interactive or real-time systems.
  */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

void FCFS(int burstTime[], int n)
{
    int waitingTime[n];
    int turnaroundTime[n];
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    
    if(n <= 0)
    {
        printf("Invalid input\n");
        return;
    }
    waitingTime[0] = 0;
    /* Please write code here */
    turnaroundTime[0] = burstTime[0];
    totalTurnaroundTime = turnaroundTime[0];
    totalWaitingTime = waitingTime[0];
    for(int i = 1; i < n; i++)
    {
        waitingTime[i]      = turnaroundTime[i - 1];
        turnaroundTime[i]   = burstTime[i] + waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        totalWaitingTime    += waitingTime[i];
    }
    
    /* End your code */
    printf("Process\tBurst Time\tWaiting Time\nTurnaround Time\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i],
                                              waitingTime[i],
                                              turnaroundTime[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}
int main()
{
    int burstTime[] = {10, 5, 8}; //Burst time for processes
    int n = sizeof(burstTime)/sizeof(burstTime[0]);
    
    FCFS(burstTime, n);
    return 0;
}