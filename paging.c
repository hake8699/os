#include<stdio.h>
void main(){
    int ms,fs,nof,np,rempages,i,j,x,y,pa,offset;
    int s[10],fno[10][20];
    printf("\nenter the memory size--");
    scanf("%d",&ms);
    printf("\nenter the page size--");
    scanf("%d",&fs);
    nof=ms/fs;
    printf("\nno. of pages available in memory are--%d",nof);
    printf("\nenter number of processes--");
    scanf("%d",&np);
    rempages=nof;
    for(i=1;i<=np;i++){
        printf("\nenter no. of pages required for p[%d]--",i);
        scanf("%d",&s[i]);
        if(s[i]>rempages){
            printf("\nmemory is full");
            break;
        }
        rempages=rempages-s[i];
        printf("\nenter page table for p[%d] (frame numbers <%d)---",i,nof);
        for(j=0;j<s[i];j++){
            printf("\nenter frame number for page number %d:",j);
            scanf("%d",&fno[i][j]);
        }
    }
    printf("\nenter logical address to find physical address");
    printf("\nenter process no. and page number and offset--");
    scanf("%d%d%d",&x,&y,&offset);
    if(x<np){
        for(i=1;i<=np;i++){
            if(y<s[i] && offset<=fs){
                pa=fno[x][y]*fs+offset;
                printf("\nThe Physical Address is--%d",pa);
                break;
            }else{
                printf("\nInvalid Process or Page Number or offset");
                break;
            }
        }
    }
}
