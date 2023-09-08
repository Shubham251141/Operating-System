#include<stdio.h>

void main()
{
    int n, i, j, temp, total = 0;
    float avg_wt, avg_tat;
    int at[20], bt[20], wt[20], tat[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sorting the burst time in ascending order using selection sort
    for(i = 0; i < n; i++)
    {
 {
        int pos = i;
        for(j = i+1; j < n; j++)
        {
            if(bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
    }

    // Calculating waiting time and turnaround time
    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;

 for(j = 0; j < i; j++)
            wt[i] += bt[j];

        tat[i] = wt[i] + bt[i];
        total += tat[i];
    }

    // Calculating average waiting time and average turnaround time
    avg_tat = (float)total/n;
    avg_wt = (float)total/n;

    // Displaying the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);