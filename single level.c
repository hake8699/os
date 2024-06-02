#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Directory{
    char dname[10];
    char fname[10][10];
    int fcnt;
};

void main(){
    int i,ch,k,flag=0;
    char f[30];
    struct Directory dir;
    dir.fcnt=0;

    printf("\nEnter name of directory -- ");
    scanf("%s",dir.dname);

    while(1){
        printf("\n\n1. Create File\t 2. Delete File\t 3. Search File\t 4. Display Files\t 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the name of the file -- ");
                scanf("%s",dir.fname[dir.fcnt]);
                dir.fcnt++;
                break;
            case 2:
                printf("\nEnter the name of the file -- ");
                scanf("%s",f);
                for(i=0;i<dir.fcnt;i++){
                    if(strcmp(f,dir.fname[i])==0){
                        printf("File %s is deleted ",f);
                        for(k=i;k<dir.fcnt-1;k++)
                            strcpy(dir.fname[k],dir.fname[k+1]);
                        dir.fcnt--;
                        flag=1;
                    }
                }
                if(flag==0)
                    printf("File %s not found",f);
                break;
            case 3:
                flag=0;
                printf("\nEnter the name of the file -- ");
                scanf("%s",f);
                for(i=0;i<dir.fcnt;i++){
                    if(strcmp(f,dir.fname[i])==0){
                        printf("File %s is found ",f);
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    printf("File %s not found",f);
                break;
            case 4:
                if(dir.fcnt==0)
                    printf("\nDirectory Empty");
                else{
                    printf("\nThe Files are -- ");
                    for(i=0;i<dir.fcnt;i++)
                        printf("\t%s",dir.fname[i]);
                }
                break;
            default:
                exit(0);
        }
    }
}
