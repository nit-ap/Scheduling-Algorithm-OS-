#include<stdio.h>
void WaitingTime(int n,int bt[],int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
      wt[i]=bt[i-1]+wt[i-1];
}
void TurnAroundTime(int n,int bt[],int wt[],int tat[])
{
   
    for(int i=0;i<n;i++)
      tat[i]=bt[i]+wt[i];
}
void AvgTime(int n,int bt[])
{
   int wt[n],tat[n],twt=0 ,ttat=0;
   WaitingTime(n,bt,wt);
      TurnAroundTime(n,bt,wt,tat);
      printf("Processes     BurstTime   WaitingTime    TurnAroundTime\n");
       for(int i=0;i<n;i++)
       {
           twt+=wt[i];
           ttat+=tat[i];
           printf("   %d  ",i+1);
           printf("          %d  ",bt[i]);
           printf("              %d  ",wt[i]);
           printf("              %d  \n",tat[i]);
       }
       float s=(float)twt/n;
       float t=(float)ttat/n;
       printf(" Average WaitingTime= %f \n ",s);
       printf(" Average TurnAroundTime= %f \n ",t);
}
int main()
{
    int n;
    printf("Enter Number of Process \n ");
    scanf("%d",&n);
    int bt[n];
     for(int i=0;i<n;i++)
       {
          printf("Enter Burst Time of Process %d ",i+1); 
          scanf("%d",&bt[i]);
       }
       AvgTime(n,bt);
       return 0;
}

//Writer :- Amit Yadav