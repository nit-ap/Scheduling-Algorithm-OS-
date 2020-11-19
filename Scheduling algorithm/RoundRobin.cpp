#include<stdio.h>
void WaitingTime(int n,int bt[],int wt[],int q)
{
    int rbt[n],t=0;
    for(int i=0;i<n;i++)
    {
        rbt[i]=bt[i];
    }
    while(true)
    {
        bool d=true;
        for(int i=0;i<n;i++)
        {
            
            if(rbt[i]>0)
            {
                d=false;
                if(rbt[i]>q)
                {
                    t+=q;
                    rbt[i]-=q;
                }
                else
                {
                    t+=rbt[i];
                    wt[i]=t-bt[i];
                    rbt[i]=0;
                }
            }
            
        }
        if(d)
         break;
           
    }
}
void TurnAroundTime(int n,int bt[],int wt[],int tat[])
{
     for(int i=0;i<n;i++)
     {
         tat[i]=bt[i]+wt[i];
     }
}
void AvgTime(int n,int bt[],int q)
{
    int wt[n],tat[n],twt=0,ttat=0;
    WaitingTime(n,bt,wt,q);
    TurnAroundTime(n,bt,wt,tat);
    printf("\nProcess \t Burst time \t Waiting time \t Turn arround time\n");
      for(int i=0;i<n;i++)
      {
         twt+=wt[i];
         ttat+=tat[i];
         printf("%d \t\t %d \t\t %d \t\t %d\n ",i+1,bt[i],wt[i],tat[i]);
      }
        printf("Average waiting time = %f",float(twt)/n);
         printf("\nAverage Turn around time  = %f",float(ttat)/n);
}
int main()
{
    int n,q;
     printf("Enter number of process=");
    scanf("%d",&n);
    int bt[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Burst time of process %d= ",i+1);
        scanf("%d",&bt[i]);
    }
     printf("\nEnter quantam time= ");
     scanf("%d",&q);
     AvgTime(n,bt,q);
     return 0;
}
//Writer:- Amit Yadav