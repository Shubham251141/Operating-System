#include<stdio.h>
 
int main()
{
 
  int c,j,n,t,rem,f=0,tq;
  int WT=0,TAT=0,AT[10],BT[10],RT[10];
  printf("Enter total no. of processes\t ");
  scanf("%d",&n);
  rem=n;
  for(c=0;c<n;c++)
  {
    printf("Enter Arrival Time and Burst Time  %d :",c+1);
    scanf("%d",&AT[c]);
    scanf("%d",&BT[c]);
    RT[c]=BT[c];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(t=0,c=0;rem!=0;)
  {
    if(RT[c]<=tq && RT[c]>0)
    {
      t+=RT[c];
      RT[c]=0;
      f=1;
    }
    else if(RT[c]>0)
{
      RT[c]-=tq;
      t+=tq;
    }
    if(RT[c]==0 && f==1)
    {
      rem--;
      printf("P[%d]\t|\t%d\t|\t%d\n",c+1,t-AT[c],t-AT[c]-BT[c]);
      WT+=t-AT[c]-BT[c];
      TAT+=t-AT[c];
      f=0;
    }
    if(c==n-1)
      c=0;
    else if(AT[c+1]<=t)
      c++;
    else
      c=0;
  }
  printf("\nAverage Waiting Time= %f\n",WT*1.0/n);
  printf("Avg Turnaround Time = %f",TAT*1.0/n);
 
  return 0;
}

//////////////////////////////////////////////////////////
OUTPUT

Enter total no. of processes     3
Enter Arrival Time and Burst Time  1 :4
5
Enter Arrival Time and Burst Time  2 :2
3
Enter Arrival Time and Burst Time  3 :4
6
Enter Time Quantum:     2


Process |Turnaround Time|Waiting Time

P[2]    |       7       |       4
P[1]    |       8       |       3
P[3]    |       10      |       4

Average Waiting Time= 3.666667
Avg Turnaround Time = 8.333333
