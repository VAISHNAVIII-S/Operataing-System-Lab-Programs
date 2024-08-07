#include <stdio.h>

typedef struct {
    int id, at, bt, ct, tat, wt;
} Process;

void calculateTimes(Process proc[], int n) {
    int total_wt = 0, total_tat = 0;
    int currentTime = 0;

    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        if (currentTime < proc[i].at) {
            currentTime = proc[i].at;
        }
        
        proc[i].ct = currentTime + proc[i].bt;
        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;

        total_wt += proc[i].wt;
        total_tat += proc[i].tat;

        currentTime += proc[i].bt;

        printf("| P%d ", proc[i].id);
    }
    printf("|\n");

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }

    printf("\nAverage TAT: %.2f\n", (float)total_tat / n);
    printf("Average WT: %.2f\n", (float)total_wt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
    }

    calculateTimes(proc, n);

    return 0;
}






/*Output:-

  Enter the number of processes: 5
Enter Arrival Time and Burst Time for Process 1: 0 4
Enter Arrival Time and Burst Time for Process 2: 1 3
Enter Arrival Time and Burst Time for Process 3: 2 1
Enter Arrival Time and Burst Time for Process 4: 3 2
Enter Arrival Time and Burst Time for Process 5: 4 5

Gantt Chart:
| P1 | P2 | P3 | P4 | P5 |

Process	AT	BT	CT	TAT	WT
P1	0	4	4	4	0
P2	1	3	7	6	3
P3	2	1	8	6	5
P4	3	2	10	7	5
P5	4	5	15	11	6

Average TAT: 6.80
Average WT: 3.80
*/
