#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n , *arr,i;
    printf("Enter the calue of n \n");
    scanf("%d",&n);
    arr = (int *)calloc(n,sizeof(int));
    for(i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i = 0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    

    return 0;
}