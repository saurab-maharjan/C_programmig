#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int i , j , k , n ;
    printf("Enter the size of matrix : ");
    scanf("%d",&n);
    float mat[n][n+1];
    for(i = 1;i<=n;i++){
        for(j = 1 ;j<=n+1;j++) {
            scanf("%f",&mat[i][j]);
        }
    }

    for(j = 1;j<=n;j++){
        for(i = 1;i<=n;i++){
            if(i!=j){
                float temp ;
                temp = mat[i][j]/mat[j][j];
                for(k = 1;k<=n+1;k++){
                   mat[i][k] -= temp*mat[j][k]; 
                }
            }
        }
    }

    
    for(i = 1;i<=3;i++){
        printf("%f\n",mat[i][n+1]/mat[i][i]);
    }

    return 0;
}