#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int i , j , k , n;
    printf("Enter the size of the matrix : ");
    scanf("%d",&n);
    float mat[n][n+1] , sum,x[n];
    

    for(i= 1;i<=n;i++){
        for(j = 1;j<=n+1;j++){
            scanf("%f",&mat[i][j]);
        }
    }
    for(i = 1;i<=n-1;i++){
        for(j = i+1;j<=n;j++){
            float temp ;
            temp = mat[j][i]/mat[i][i];
            for(k = 1;k<=n+1;k++){
                mat[j][k] -= temp * mat[i][k];
            }
        }
    }

    x[n] = mat[n][n+1]/mat[n][n];
    for(i = n-1 ;i>=1;i--){
        sum = 0;
        for(j = i+1;j<=n;j++){
            sum += mat[i][j] * x[j];
        }
        
        x[i] = (mat[i][n+1]-sum)/mat[i][i];
    }
    for(i = 1;i<=n;i++){
        printf("%f\t",x[i]);
    }
    return 0;
}
