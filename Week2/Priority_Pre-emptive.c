#include <stdio.h>
#include <limits.h>

typedef struct {
    int id, at, bt, ct, tat, wt, rt, priority, remaining_bt;
} Process;

void calculateTimes(Process proc[], int n) {
    int complete = 0, time = 0, highest_priority = INT_MAX, check = 0;
    int total_wt = 0, total_tat = 0, total_rt = 0;

    for (int i = 0; i < n; i++)
        proc[i].remaining_bt = proc[i].bt;

    printf("\nGantt Chart:\n");
    while (complete != n) {
        int shortest = -1;
        highest_priority = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (proc[j].at <= time && proc[j].remaining_bt > 0 && proc[j].priority < highest_priority) {
                highest_priority = proc[j].priority;
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

        if (proc[shortest].remaining_bt == 0) {
            complete++;
            check = 0;
            proc[shortest].ct = time;
            proc[shortest].tat = proc[shortest].ct - proc[shortest].at;
            proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;
            proc[shortest].rt = proc[shortest].ct - proc[shortest].bt - proc[shortest].at;

            total_wt += proc[shortest].wt;
            total_tat += proc[shortest].tat;
            total_rt += proc[shortest].rt;
        }
    }
    printf("|\n");

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].at, proc[i].bt, proc[i].priority, proc[i].ct, proc[i].tat, proc[i].wt, proc[i].rt);
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
        printf("Enter Arrival Time, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].at, &proc[i].bt, &proc[i].priority);
    }

    calculateTimes(proc, n);

    return 0;
}

/*
Output:-

Enter the number of processes: 5
Enter Arrival Time, Burst Time, and Priority for Process 1: 0
3
3
Enter Arrival Time, Burst Time, and Priority for Process 2: 1
4
2
Enter Arrival Time, Burst Time, and Priority for Process 3: 2
6
4
Enter Arrival Time, Burst Time, and Priority for Process 4: 3
4
6
Enter Arrival Time, Burst Time, and Priority for Process 5: 5
2
10

Gantt Chart:
| P1 | P2 | P2 | P2 | P2 | P1 | P1 | P3 | P3 | P3 | P3 | P3 | P3 | P4 | P4 | P4 | P4 | P5 | P5 |

Process	AT	BT	Priority	CT	TAT	WT	RT
P1	0	3	3		7	7	4	4
P2	1	4	2		5	4	0	0
P3	2	6	4		13	11	5	5
P4	3	4	6		17	14	10	10
P5	5	2	10		19	14	12	12

Average TAT: 10.00
Average WT: 6.20
Average RT: 6.20

*/
