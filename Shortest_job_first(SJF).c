#include <stdio.h>
void main()
{
    int BT[20], pro[20], WT[20], Tat[20],i,j,no,tot=0,pos,tempo;
    float avgwt, avgtat;
    printf("Enter the no of processes");
    scanf("%d", &no);
   
    printf("Enter the burst time");
    for(i=0;i<no;i++)
    {
        scanf("%d", &BT[i]);
        pro[i]=i+1;
    }
    //Sorting the burst time in ascending order using selection Sort
    for(i=0;i<no;i++)
    {
        pos=i;
        for(j=i+1;j<no;j++)
        {
            if(BT[j]<BT[pos])
            pos=j;
        }
        tempo=BT[i];
        BT[i]=BT[pos];
        BT[pos]=tempo;
tempo=pro[i];
        pro[i]=pro[pos];
        pro[pos]=tempo;
    }
   
    WT[0]=0;   //Waiting time for the first process will be zero
   
    //Calculate waiting time
    for(i=1;i<no;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
        WT[i]=WT[i]+BT[j];
       
        tot=tot+WT[i];
    }
   
    avgwt=(float)tot/no; //average waiting time
    tot=0;
   
    printf("\nProcess\t   Burst Time   \tWaiting Time\tTurnaround Time ");
    for(i=0;i<no;i++)
    {
        Tat[i]=BT[i]+WT[i];
        tot=tot+Tat[i];
        printf("\n%d\t\t   %d\t\t    %d\t\t        %d\t\t%d", pro[i], BT[i],WT[i], Tat[i]);
       
    }
 avgtat=(float)tot/no;
    printf("\n\nAverage Waiting Time=%f", avgwt);
    printf("\nAverage Turnaround Time=%f\n", avgtat);
   
}
