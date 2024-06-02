#include<stdio.h>
#define PROCESSES 10
#define RESOURCES 10
int available[RESOURCES],work[RESOURCES];
int max[PROCESSES][RESOURCES];
int allocation[PROCESSES][RESOURCES];
int need[PROCESSES][RESOURCES];
int p,r,finish[PROCESSES];

int safety(){
    int safeSequence[PROCESSES];
    int count=0,j,i,k,flag=0;
    for (i=0;i<r;i++) {
        work[i]=available[i];
    }
    for(i=0;i<p;i++){
        finish[i]=0;
    }
    while(count<p){
        flag=0;
        for(i=0;i<p;i++){
            if(!finish[i]){
                for(j=0;j<r;j++){
                    if(need[i][j]>work[j])
                        break;
                }
                if(j==r){ 
                    for(k=0;k<r;k++){
                        work[k]+=allocation[i][k];
                    }
                    safeSequence[count++]=i;
                    finish[i]=1;
                    flag=1;
                }
            }
        }
        if(!flag){ 
            printf("System is in unsafe state!\n");
            return 0;
        }
    }
    printf("Safe sequence: ");
    for(i=0;i<p-1;i++)
        printf("P%d -> ",safeSequence[i]);
    printf("P%d\n",safeSequence[p-1]);
    return 1;
}

int requestResources(int process,int request[]){
    for(int i=0;i<r;i++){
        if(request[i]>need[process][i]||request[i]>available[i])
            return 0;
    }
    for (int i=0;i<r;i++){
        available[i]-=request[i];
        allocation[process][i]+=request[i];
        need[process][i]-=request[i];
    }
    if(!safety()){
        for(int i=0;i<r;i++){
            available[i]+=request[i];
            allocation[process][i]-=request[i];
            need[process][i]+=request[i];
        }
        return 0;
    }
    return 1;
}

int main(){
    int process;
    int request[RESOURCES];
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    printf("Enter the number of resources: ");
    scanf("%d",&r);
    printf("Enter the maximum demand of each process:\n");
    for(int i=0;i<p;i++){
        printf("For process %d: ",i);
        for(int j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the allocation for each process:\n");
    for(int i=0;i<p;i++){
        printf("For process %d: ",i);
        for(int j=0;j<r;j++){
            scanf("%d",&allocation[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    printf("Enter the available resources: ");
    for(int i=0;i<r;i++){
        scanf("%d",&available[i]);
    }
    safety(); 
    printf("\nEnter the process number making the request: ");
    scanf("%d",&process);
    printf("Enter the request for each resource: ");
    for(int i=0;i<r;i++){
        scanf("%d",&request[i]);
    }
    if(requestResources(process,request)){
        printf("Request granted!\n");
    }else{
        printf("Request denied! System will be in unsafe state.\n");
    }
    return 0;
}
