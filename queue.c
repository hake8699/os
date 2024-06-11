#include<stdio.h>
#include<stdlib.h>
# define ms 5
int q[ms];
int f=-1;
int r=-1;
void insert(int ele)
{
    if(r==ms-1)
    {
        printf("queue is full!!");
        return;
    }
    if(f==-1)
    {
        f=0;
    }
    q[++r]=ele;
}

void display()
{
    int i;
    if(f==-1)
    {
        printf("queue is empty");
        return;
    }
    printf("the elements present in quueu is");
    for(i=f;i<=r;i++)
    {
        printf("%d",q[i]);
    }
    printf("\n");
}


void delete()
{
    if(f==-1){
        printf("queue is empty");
        return;
    }
    printf("the deleted elements in the queue is:%d\n",q[f++]);
    if(f>r){
        f=r=-1;
    }
}

int main()
{
    int ch,ele;
    while(1){
        printf("\n1.insert \n2.delete \n3.display \n4.exit");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            
                printf("enter the element u want to insert ");
                scanf("%d",&ele);
                insert(ele);
                break;
            
            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("exiting");
            exit(0);


            default:
            printf("invalid choice");
        }

    }
    return 0;
}