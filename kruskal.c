#include<stdio.h>
#include<stdlib.h>
int cost[20][20],n,v1,v2;
int root[10];
void findmin()
{
    int j,i,min=999;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cost[i][j]!=0 && cost[i][j]<min)
            {
                min=cost[i][j];
                v1=i;
                v2=j;
            }
        }
    }
}
void read_mat()
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
}
void print_mat()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",cost[i][j]);
        }
    
    printf("\n");
    }
}
void dounion()
{
    int temp,i;
    temp=root[v2];
    for(i=0;i<n;i++)
    {
        if(root[i]==temp)
        root[i]=root[v2];
    }
}

void kruskal()
{
    int edgemin,i,tot=0;
    for(i=0;i<n;i++)
    root[i]=i;
    i=0;
    while(i!=n-1)
    {
        findmin();
        edgemin=cost[v1][v2];
        cost[v1][v2]=cost[v2][v1]=0;
        if(root[v1!=root[v2]])
        {
            printf("%d-->%d=%d",v1,v2,edgemin);
            dounion();
            tot+=edgemin;
            i++;
        }
    }
        printf("\n mincost=%d",tot);
    
}

void main()
{
    printf("enter the no of virtex");
    scanf("%d",&n);
    printf("enter the cam");
    read_mat();
    printf("===CAM==");
    print_mat();
    kruskal();
}