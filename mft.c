#include <stdio.h>
int main(){
    int tm,om,n,i,block_size,internal_frag=0,ex_frag,waste;
    printf("Enter total memory size, memory for OS, No. of processes: ");
    scanf("%d %d %d",&tm,&om,&n);
    int process[n];
    tm-=om;
    block_size=tm/n;
    ex_frag=tm-block_size*n;
    for(i=0;i<n;i++) {
        printf("Enter size of process %d: ",i+1);
        scanf("%d",&process[i]);
        if(process[i]<= block_size){
            waste=block_size-process[i];
            internal_frag+=waste;
            printf("Memory allocated to process %d is: %d\n",i+1,process[i]);
        }else{
            printf("Process %d is blocked, no sufficient memory available\n",i+1);
            ex_frag+=block_size;
        }
    }
    printf("Total memory for user space = %d.\n",tm);
    printf("External Fragmentation is %d.\n",ex_frag);
    printf("Internal Fragmentation is %d\n",internal_frag);
    return 0;
}
