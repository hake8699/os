#include<stdio.h>
#include<stdlib.h>
#define buffsize 3
int in=0,out=0,buff[10],nextP,nextC,mutex=1,full=0,empty=buffsize;
int wait(int s){
    return (--s);
}
int signal(int s){
    return (++s);
}
void producer(){
    printf("Enter the item produced:");
    scanf("%d",&nextP);
    empty=wait(empty);
    mutex=wait(mutex);
    buff[in]=nextP;
    in=(in+1)%buffsize;
    mutex=signal(mutex);
    full=signal(full);
}
void consumer() {
    full=wait(full);
    mutex=wait(mutex);
    nextC=buff[out];
    printf("\nConsumer consumes item %d",nextC);
    out=(out+1)%buffsize;
    mutex=signal(mutex);
    empty=signal(empty);
}
void main() {
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1) {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n) {
            case 1:
                if((mutex==1)&&(empty!=0))
                    producer();
                else
                    printf("Buffer is full");
                break;
            case 2:
                if((mutex==1)&&(full!=0))
                    consumer();
                else
                    printf("Buffer is empty!");
                break;
            case 3:
                return 0;
        }
    }
}
