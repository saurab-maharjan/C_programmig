#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,*ptr,b,sum,n,i;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    ptr =(int*)malloc(n*sizeof(int));
    printf("enter the elament\n");
    sum = 0;
    for(i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("sum = %d\n",sum);
    for(i=0;i<n;i++){
        printf("%d\n",*(i+ptr));
    }
    free(ptr);
    return 0;



}