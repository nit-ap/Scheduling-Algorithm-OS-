#include<stdio.h>
struct process
{
    int bt;
    int art;
};
void WaitingTime(process p[],int n,int wt[])
{
    int rt[n],c=0,t=0,min=123456789, s=0,f=0;
    bool ch=false;
    for(int i=0;i<n;i++)
    {
        rt[i]=p[i].bt;
    }
    while(c!=n)
    {
        for(int j=0;j<n;j++)
        {
            if((p[j].art<=t)&&(rt[j]<min)&&rt[j]>0)
            {
                min=rt[j];
                s=j;
                ch=true;
            }
        }
        if(ch==false)
        {t++;
        continue;
        }
        rt[s]--;
        min=rt[s];
        if(min==0)
        min=123456789;
        if(rt[s]==0)
        {
            c++;
            ch==false;
            f=t+1;
            wt[s]=f-p[s].bt-p[s].art;
            if(wt[s]<0)
            wt[s]=0;
        }
        t++;
    }
    
}
void TurnAroundTime(process p[],int n,int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=p[i].bt+wt[i];
    }
}
void AvgTime(int n,process p[])
{
   int wt[n],tat[n],twt=0,ttat=0;
   WaitingTime(p,n,wt);
   TurnAroundTime(p,n,wt,tat);
   printf("Process \t Burst Time \t Waiting Time \t TurnAroundTime");
   
    for(int i=0;i<n;i++)
    {
        twt+=wt[i];
        ttat+=tat[i];
        printf("\n %d \t\t %d \t\t %d \t\t %d",i+1,p[i].bt,wt[i],tat[i]);
    }
    printf("\n Average WaitingTime = %f",(float)twt/n);
     printf("\n Average TurnAroundTime = %f",(float)ttat/n);
}
int main()
{
    int n;
    printf("Enter Number of process = ");
    scanf("%d",&n);
    process p[n];
     for(int i=0;i<n;i++)
     {
         printf("\nEnter Burst Time of process %d = ",i+1);
         scanf("%d",&p[i].bt);
     }
     for(int i=0;i<n;i++)
     {
         printf("\nEnter Arival time of process %d = ",i+1);
         scanf("%d",&p[i].art);
     }
     AvgTime(n,p);
     return 0;
}
//Writer:-Amit Yadav