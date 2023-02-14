#include<stdio.h>
struct process
{
    int pno;
    int atime;
    int btime;
    int ct;
    int wt;
    int tat;
} p[10];

int main()
{
    int n;
    printf("enter the number of processes : ");
    scanf("%d", &n);
    printf("enter the arrival time and burst time : ");
    for (int i = 0; i < n; i++)
    {
        p[i].pno =i+1;
        scanf("%d %d", &(p[i].atime), &(p[i].btime));
    }

    for(int i=1;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(p[j].atime>p[j+1].atime)
            {
                struct process temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    int t=0,y=0;
    while(y<n)
    {
        if(p[y].atime<=t)
        {
            t+=p[y].btime;
            printf("P[%d] %d",p[y].pno,t);
            p[y].ct=t;
            p[y].tat=p[y].ct-p[y].atime;
            p[y].wt=p[y].tat-p[y].btime;
            y++;
        }
        else 
        t++;
    }

    float awt=0.0,atat=0.0;
    for(int i=0;i<n;i++)
    {
        awt+=p[i].wt;
        atat+=p[i].tat;
    }
    awt=(float)awt/n;
    atat=(float)atat/n;

    printf("\nAverage waiting time is : %f",awt);
    printf("Average turnaround time is : %f\n",atat);
}