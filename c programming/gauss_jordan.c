#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n , i , j , k;
    float temp ;
    printf("Enter the ordeer of the matrix : ");
    scanf("%d",&n);
    float matrix[n][n+1];
    for(j = 0;j <n;j++){
        for(i = 0;i<n+1;i++){
            printf("Enter the (%d , %d) element : " , j,i);
            scanf("%f",&matrix[j][i]);
        }
    }
    for(j = 0;j<n;j++){
        if(fabs(matrix[j][j])<0.000005){
            printf("No solution to these equations \n");
            exit(0);
        }
        for(i = 0;i<n;i++){
            if(i!=j){
                temp = matrix[i][j];
                for(k = 0;k<n+1;k++){
                    matrix[i][k] -= (temp/matrix[j][j])*matrix[j][k];
                }
            }
        }
    }
    printf("Solution : \n");
    for(i = 0;i<n;i++){
        printf(": %f\n", matrix[i][n]/matrix[i][i]);
    }

    

    return 0;
}