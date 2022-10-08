#include <stdio.h>
/*
Process Id	Arrival time	Burst time    Completion time     TAT      WT
    P1	          3	            4              7               4       0
    P2	          5	            3              13              8       5
    P3	          0	            2              2               2       0
    P4	          5	            1              14              9       8
    P5	          4	            3              10              6       3
*/

struct process
{
    int AT,WT,TT,BT;
};


int main(){
    struct process a[10];
    int n;
    int burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    printf("Enter number of process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("At BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].AT,&a[i].BT);
    }
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
            a[i].WT=a[i].AT;
        else
            a[i].WT=burst-a[i].AT;
        burst+=a[i].BT;
        Total+=a[i].WT;
    }
    Avg_WT=Total/n;
    
    cmpl_T=0;
    Total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=a[i].BT;
        a[i].TT=cmpl_T-a[i].AT;
        Total+=a[i].TT;
    }
    Avg_TT=Total/n;
    
    
    printf("Process ,  Waiting_time ,  TurnA_time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,a[i].WT,a[i].TT);
    }
    printf("Average waiting time is : %f\n",Avg_WT);
    printf("Average turn around time is : %f\n",Avg_TT);
    return 0;
}