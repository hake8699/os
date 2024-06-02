#include<stdio.h>
void main(){
    int p[20],bt[20],wt[20],tat[20],i,k,n,temp;
    float wtavg=0,tatavg=0;
    int tottime=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        p[i]=i;
        printf("Enter burst time for process %d:",i);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++) {
        for(k=i+1;k<n;k++) {
            if(bt[i]>bt[k]) {
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
        }
    }
    for(i=0;i<n;i++) {
        tottime+=bt[i];
        tat[i]=tottime;
        wt[i]=tottime-bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    printf("\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++) {
        printf("\n\tp%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time=%f",wtavg/n);
    printf("\nAverage Turnaround Time=%f",tatavg/n);
}
