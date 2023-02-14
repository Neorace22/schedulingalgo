#include <stdio.h>
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
    printf("enter the arrival time and burst time");
    for (int i = 0; i < n; i++)
    {
        p[i].pno = i + 1;
        scanf("%d %d", &(p[i].atime), &(p[i].btime));
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].btime > p[j + 1].btime)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }


    int t = 0, y = 0;
    while (y < n)
    {

        for (int i = 0; i < n; i++)
        {
            if (p[i].atime <= t && p[i].btime != 0)
            {
                t++;
                printf("P[%d]%d", p[i].pno, t);
                p[i].ct = t;
                p[i].tat = p[i].ct - p[i].atime;
                p[i].wt = p[i].tat - p[i].btime;
                p[i].btime --;
                if(p[i].btime==0)
                y++;
                break;
            }
        }
    }
    float awt = 0.0, atat = 0.0;
    for (int i = 0; i < n; i++)
    {
        awt += p[i].wt;
        atat += p[i].tat;
    }
    awt = (float)awt / n;
    atat = (float)atat / n;

    printf("Average waiting time is : %f", awt);
    printf("Average turnaround time is : %f", atat);
}