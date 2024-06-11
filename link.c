#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
    int data;
    struct linkedlist *ptr;
};

typedef struct linkedlist *node;
node head=NULL;

node createnode(){
    node temp;
    temp=(node)malloc(sizeof(struct linkedlist));
    temp->ptr=NULL;
    return temp;
}

node insert_end(int ele){
    node temp;
    temp=createnode();
    temp->data=ele;
    if(head==NULL){
        head=temp;
    }else{
        temp->ptr=head;
        head=temp;
    }
    return head;
}

node insert_begin(int ele){
    node temp,p;
    temp=createnode();
    temp->data=ele;
    if(head==NULL){
        head=temp;
    }else{
        p=head;
        while(p->ptr!=NULL){
            p=p->ptr;
        }
        p->ptr=temp;
    }
    return head;
}

node delete_begin(){
    node temp;
    temp=head;
    if(head==NULL){
        printf("Empty list");
    }else if(head->ptr==NULL)
        head=NULL;
        else
        head=head->ptr;
        free(temp);
    return head;
}

node delete_end(){
    node temp,prev;
    temp=head;
    if(head==NULL)
        printf("\nEmpty list");
    else if(head->ptr==NULL)
        head=NULL;
    else{
        while(temp->ptr!=NULL){
            prev=temp;
            temp=temp->ptr;
        }
        prev->ptr=NULL; 
    }
    free(temp);
    return head;
}

node delete_specific(int ele){
    node temp,prev;
    temp=head;
    if(head==NULL)
        printf("\nEmpty list");
    else if(head->data==ele){
        if(head->ptr!=NULL)
            head=head->ptr;
        else
            head=NULL;
        }else{
            while(temp->data!=ele && temp->ptr!=NULL){
                prev=temp;
                temp=temp->ptr;
            }
            if(temp->ptr==NULL && temp->data!=ele)
                printf("Specified item not found");
        else if(temp->ptr!=NULL){
            prev->ptr=temp->ptr;
        }else{
            prev->ptr=NULL;
        }
        free(temp);
        return head;
}
}

void display(){
    node temp;
    temp=head;
    if(head==NULL){
        printf("Empty list.");
        return;
    }
    printf("\nelements of the list are: \n");
    while(temp->ptr!=NULL){
        printf("%d\t",temp->data);
        temp=temp->ptr;
    }
    printf("%d\t",temp->data);
}

int main(){
    int ele,opt=1,ch;
    printf("\nSingly linked list\n");
    while(opt){
    printf("\n1.INSERT END\n2.DISPLAY\n3.INSERT BEGIN\n4.DELETE BEGIN\n5.DELETE END\n6.DELETE SPECIFIC\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1: 
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&ele);
        insert_begin(ele);
        break;
    case 2:
        display();
        break;
    case 3:
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&ele);
        insert_end(ele);
        break;
    case 4:
        delete_begin();
        break;
    case 5:
        delete_end();
        break;
    case 6:
        printf("\nEnter the key value: ");
        scanf("%d",&ele);
        delete_specific(ele);
        break;
    default:   
        printf("Wrong choice!!");
        return 0;
    }
    printf("\nDo you want to continue(0/1)?");
    scanf("%d",&opt);
}
return 0;
}
