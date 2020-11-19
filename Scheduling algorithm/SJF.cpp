#include<stdio.h>
#include<math.h>
struct Process{
    int bt;
    int at;
};
void WaitingTime(int n,Process p[],int wt[])
{
    int r[n];
    for(int i=0;i<n;i++)
    {
         r[i]=p[i].bt;
    }
     int c=0,t=0,min=12478956,s=0,f;
     bool ch=false;
     while(c!=n)
     {
         for(int i=0;i<n;i++)
         {
             if(p[i].at<=t&&r[i]<min&&r[i]>0)
             {
                 min=r[i];
                 s=i;
                 ch=true;
             }
         }
         if(ch==false)
         {
             t++;
             continue;
         }
         r[s]--;
         min=r[s];
         if(min==0)
         min=123478956;
         
         if(r[s]==0)
         {
             c++;
             ch==false;
             f=t+1;
             wt[s]=f-p[s].bt-p[s].at;
             if(wt[s]<0)
              wt[s]=0;
         }
         t++;
     }
    
}
void TurnAroundTime( int n,Process p[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    tat[i]=p[i].bt+wt[i];
}
void AvgTime(int n,Process p[])
{
    int wt[n],tat[n],twt=0,ttat=0;
    WaitingTime(n,p,wt);
    TurnAroundTime(n,p,wt,tat);
    printf("Process   BurstTime  WaitingTime   TurnAroundTime \n");
    for(int i=0;i<n;i++)
    {
        twt+=wt[i];
        ttat+=tat[i];
        printf("%d \t     %d  \t   %d  \t       %d\n",i+1,p[i].bt,wt[i],tat[i]);
        
    }
    printf("Average Waiting Time =%f\n",(float)twt/n);
    printf("Average Turn Around Time =%f",(float)ttat/n);
}
int main()
{
    int n;
    printf("Enter Number Process:\n");
    scanf("%d",&n);
   Process p[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Burst time of process %d: ",i+1);
        scanf("%d",&p[i].bt);
    }
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Arival time of process %d: ",i+1);
        scanf("%d",&p[i].at);
    }
    
    AvgTime(n,p);
    return 0;
}
//writer:- Amit Yadav