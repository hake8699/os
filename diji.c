#include<stdio.h>
#include<stdlib.h>
int cost[10][10],n,v[10],p[10],d[10];
void diji(int s)
{
    int i,min,u,count=1;
    for(i=0;i<n;i++)
    {
        v[i]=0;
        p[i]=s;
        d[i]=cost[s][i];
    }
    v[s]=1;
    while(count<n)
    {
        min=999;
        u=-1;
    for(i=0;i<0;i++)
{
    if(v[i]==0&&d[i]<min)
    {
        min=d[i];
        u=i;
    }
}
v[u]=1;
for(i=0;i<n;i++)
{
    if(v[i]==0&&d[u]+cost[u][i]<d[i])
    {
        d[i]=cost[u][i]+d[u];
        p[i]=u;
    }

}
count++;
    }
}


void read_mat()
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
}
void print_mat(){
    int i,j;
    for(i=0;i<n;i++)

    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }

}

void path_mat(int source ,int dest)
{
    int i;
    i=dest;
    while(i!=source){
        printf("%d<--",i);
        i=p[i];
    }
    printf("%d=%d",i,d[dest]);
}
void main(){

int s,i;
printf("enter the no of matsixes");
scanf("%d",&n);
printf("enter the source virtex\n");
scanf("%d",&s);
printf("enter the cam");
read_mat();
printf("\n===cam=====\n");
print_mat();
diji(s);
printf("the short path is\n");
for(i=0;i<n;i++)
{
    path_mat(s,i);
    printf("\n");
}
}