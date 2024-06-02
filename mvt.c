#include<stdio.h>
#include<string.h>
int main(){
    int tm,mp[10],i,pid[50],temp,n=0,osm,allotedpc=0,allotedp[50],flag[50];
    char ch='y';
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d",&tm);
    printf("Enter the memory required by OS (in Bytes): ");
    scanf("%d",&osm);
    tm-=osm;
    temp=tm;
    for(i=0;i<50;i++) {
        flag[i]=0;
    }
    for(i=0;ch=='y';i++,n++){
        printf("Enter memory required for process %d (in Bytes): ",i+1);
        scanf("%d",&mp[i]);
        if(mp[i]<=temp){
            printf("Memory is allocated for Process %d\n",i+1);
            temp-=mp[i];
            flag[i]=1;
        }else{
            printf("No sufficient memory available\n");
            flag[i]=0;
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c",&ch);
    }
    printf("\nTotal Memory Available: %d",tm);
    printf("\n\n\tPROCESS\t\tMEMORY ALLOCATED\n");
    for(i=0;i<n;i++) {
        if(flag[i]==0) continue;
        printf("\t%d\t\t%d\n",i+1,mp[i]);
    }
    printf("Total Memory Allocated: %d\n",tm-temp);
    printf("Total External Fragmentation: %d\n",temp);
    return 0;
}
