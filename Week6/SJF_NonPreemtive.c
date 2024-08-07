#include <stdio.h>

typedef struct {
    int id, at, bt, ct, tat, wt;
} Process;

void calculateTimes(Process proc[], int n) {
    int complete = 0, time = 0;
    int total_wt = 0, total_tat = 0;
    int shortest = -1, min_bt = 0;
    int finish_time;
    int check = 0;

    for (int i = 0; i < n; i++) {
        proc[i].ct = proc[i].tat = proc[i].wt = 0;
    }

    while (complete != n) {
        shortest = -1;
        min_bt = 10000;

        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= time) && (proc[j].ct == 0) && (proc[j].bt < min_bt)) {
                min_bt = proc[j].bt;
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            time++;
            continue;
        }

        proc[shortest].ct = time + proc[shortest].bt;
        proc[shortest].tat = proc[shortest].ct - proc[shortest].at;
        proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;

        total_wt += proc[shortest].wt;
        total_tat += proc[shortest].tat;

        time += proc[shortest].bt;
        complete++;
        check = 0;
    }

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

/*

OutPut:

Enter the number of processes: 5
Enter Arrival Time and Burst Time for Process 1: 2 6 
Enter Arrival Time and Burst Time for Process 2: 5 2
Enter Arrival Time and Burst Time for Process 3: 1 8
Enter Arrival Time and Burst Time for Process 4: 0 3
Enter Arrival Time and Burst Time for Process 5: 4 4

Process	AT	BT	CT	TAT	WT
P1	2	6	9	7	1
P2	5	2	11	6	4
P3	1	8	23	22	14
P4	0	3	3	3	0
P5	4	4	15	11	7

Average TAT: 9.80
Average WT: 5.20
*/
