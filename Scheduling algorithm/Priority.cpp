#include<stdio.h>
struct process
{   int pid;
    int bt;
    int pr;
};
void WaitingTime(process p[],int n,int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=p[i-1].bt+wt[i-1];   
    }
}
void TurnAroundTime(process p[],int n,int wt[],int tat[])
{
   for(int i=0;i<n;i++)
    {
        tat[i]=p[i].bt+wt[i];   
    } 
}
void AvgTime(process p[],int n)
{
    int wt[n],tat[n],twt=0,ttat=0;
    WaitingTime(p,n,wt);
    TurnAroundTime(p,n,wt,tat);
    printf("\nProcess \t BurstTime \t WaitingTime \t TurnAroundTime");
    
      for(int i=0;i<n;i++)
      {
          twt+=wt[i];
          ttat+=tat[i];
          printf("\n %d \t\t %d \t\t %d \t\t %d",p[i].pid,p[i].bt,wt[i],tat[i]);
      }
      printf("\n Average Waiting Time = %f",(float)twt/n);
      printf("\n Average Turn Around Time = %f",(float)ttat/n);
}
void PriorityScheduling(process p[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
             if(p[j].pr>p[j+1].pr) 
             {
                 process temp=p[j];
                 p[j]=p[j+1];
                 p[j+1]=temp;
             }
        }
    }
     printf("Order in which process gets executed \n");
    for(int i=0;i<n;i++)
    {
       printf(" %d ",p[i].pid);
    }
     AvgTime(p,n);
}
int main()
{
    int n;
    printf("Enter Number of process =");
    scanf("%d",&n);
    process p[n];
     for(int i=0;i<n;i++)
     {    p[i].pid=i+1;
          printf("\nEnter Burst time of process %d=",i+1);
          scanf("%d",&p[i].bt);
     }
      for(int i=0;i<n;i++)
     {
          printf("\nEnter Priority of process %d=",i+1);
          scanf("%d",&p[i].pr);
     }
    PriorityScheduling(p,n);
     return 0;
}
//Writer:-Amit Yadav