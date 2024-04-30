#include <stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], pri[20], n, total = 0, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    printf("Enter priority of each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d: ", i + 1);
        scanf("%d", &pri[i]);
    }

    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (pri[i] > pri[k])
            {
                temp = p[i], p[i] = p[k], p[k] = temp;
                temp = bt[i], bt[i] = bt[k], bt[k] = temp;
                temp = pri[i], pri[i] = pri[k], pri[k] = temp;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("p%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total / n);

    return 0;
}