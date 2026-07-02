/* Priority Scheduling
 * It is a CPU scheduling algorithm that select the highest process for execution.
 * It can be implemented in either preemptive (co ngat quang)
 * or non-preemptive (khong ngat quang) mode.
 *      - Preemptive: OS can interrupt a running process and change to higher process
 *                    or after a time exprirs.
 *      - Non-preemptive: Once a process gets the CPU, it executes until finishes.
 */

 /* Pros and Cons
  * Pros:
  *     - Executes high-priority processes first.
  *     - Reduces waiting time for critial tasks.
  *     - Simple to implement.
  * Cons:
  *     - high-priority tasks use a lot of CPU time,
  *       so lower-priority tasks may postponed indefinitely.
  *     - 
  */

#include <stdio.h>

typedef struct
{
    int pid;
    int burstTime;
    int priority;
}process_t;

void priority_scheduling(process_t proc[], int numProc)
{
    /* Please write code here */
    for(int i = 0; i < numProc; i++)
    {
        for(int j = i + 1; j < numProc; j++)
        {
            process_t temp = proc[i];
            if(proc[j].priority < proc[i].priority)
            {
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    /* End your code */
    int currentTime = 0;
    printf("Priority Scheduling:\n");

    for(int i = 0; i < numProc; i++)
    {
        printf("Executing process P%d for %dms\n", proc[i].pid, proc[i].burstTime);
        currentTime += proc[i].burstTime;
    }
}

int main()
{
    process_t proc[] = 
    {
        {1, 12, 12},
        {2, 5, 5},
        {3, 4, 4}
    };


    int numProc = sizeof(proc) / sizeof(proc[0]);

    priority_scheduling(proc, numProc);

    return 0;
}