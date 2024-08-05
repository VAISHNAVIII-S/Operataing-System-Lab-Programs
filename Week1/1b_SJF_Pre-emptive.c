#include <stdio.h>
#include <limits.h>

typedef struct {
    int id, at, bt, ct, tat, wt, rt, remaining_bt;
} Process;

void calculateTimes(Process proc[], int n) {
    int complete = 0, time = 0, shortest = 0;
    int min_bt = INT_MAX;
    int check = 0;
    int total_wt = 0, total_tat = 0, total_rt = 0;
    int finish_time = 0;

    // Initialize remaining burst time
    for (int i = 0; i < n; i++)
        proc[i].remaining_bt = proc[i].bt;

    printf("\nGantt Chart:\n");
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (proc[j].at <= time && proc[j].remaining_bt < min_bt && proc[j].remaining_bt > 0) {
                min_bt = proc[j].remaining_bt;
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            time++;
            continue;
        }

        printf("| P%d ", proc[shortest].id);
        proc[shortest].remaining_bt--;
        time++;

        min_bt = proc[shortest].remaining_bt;
        if (min_bt == 0)
            min_bt = INT_MAX;

        if (proc[shortest].remaining_bt == 0) {
            complete++;
            check = 0;
            finish_time = time;
            proc[shortest].ct = finish_time;
            proc[shortest].tat = proc[shortest].ct - proc[shortest].at;
            proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;
            proc[shortest].rt = proc[shortest].ct - proc[shortest].bt - proc[shortest].at;

            total_wt += proc[shortest].wt;
            total_tat += proc[shortest].tat;
            total_rt += proc[shortest].rt;
        }
    }
    printf("|\n");

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt, proc[i].rt);
    }

    printf("\nAverage TAT: %.2f\n", (float)total_tat / n);
    printf("Average WT: %.2f\n", (float)total_wt / n);
    printf("Average RT: %.2f\n", (float)total_rt / n);
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









/*Output 
Enter the number of processes: 5
Enter Arrival Time and Burst Time for Process 1: 2
6
Enter Arrival Time and Burst Time for Process 2: 5
2
Enter Arrival Time and Burst Time for Process 3: 1
8
Enter Arrival Time and Burst Time for Process 4: 0
3
Enter Arrival Time and Burst Time for Process 5: 4
4

Gantt Chart:
| P4 | P4 | P4 | P1 | P5 | P2 | P2 | P5 | P5 | P5 | P1 | P1 | P1 | P1 | P1 | P3 | P3 | P3 | P3 | P3 | P3 | P3 | P3 |

Process	AT	BT	CT	TAT	WT	  RT
P1	    2	  6	  15 	 13	  7  	7
P2	    5	  2	  7	   2	  0	  0
P3	    1	  8	  23	 22	  14	14
P4	    0	  3	  3	    3	  0	  0
P5	    4	  4	  10	  6	  2	  2

Average TAT: 9.20
Average WT: 4.60
Average RT: 4.60
*/
