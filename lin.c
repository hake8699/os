:-  #include<stdio.h>
int main(){
    int i,n,key,index=-1;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array elements are: \n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("Enter the searching elCodement: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(key==a[i]){
            index=i;
            break;
        }
    }
    if(index!=-1){
        printf("%d is found %d index",key,index);
    }else{
        printf("%d is not found",key);
    }
}
