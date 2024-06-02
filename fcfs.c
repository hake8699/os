#include<stdio.h>
void main(){
    int bt[20],wt[20],tat[20],i,n;
    float wtavg =0,tatavg=0;
    int tottime =0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter burst time for processes %d: ",i);
        scanf("%d",&bt[i]);
        }
        for(i=0;i<n;i++){
            tottime+=bt[i];
            tat[i]=tottime;
            wt[i]=tat[i]-bt[i];
            wtavg=wtavg+wt[i];
            tatavg=tatavg+tat[i];
        }
        printf("\t PROCESS \t BURST TIME\t WATING TIME\t TURNAROUND TIME \n");
        for(i=0;i<n;i++)
            printf("\n\t p%d \t\t  %d\t\t  %d\t\t  %d",i,bt[i],wt[i],tat[i]);
            printf("\nAverage Wating Time: %f\n",wtavg/n);
            printf("\n Average Turnaround Time: %f\n",tatavg/n);
}
