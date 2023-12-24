#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int i , j , k , n ;
    printf("Enter the size of matrix :  ");
    scanf("%d",&n);
    double a[n][n] , b[n] , max , temp , lem = 1, sum,c[n];
    printf("Enter the element of the matrix  : ");
    for(i = 0;i<n;i++){
        for(j = 0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    printf("Enter the  column vector : ");
    for(i = 0;i<n;i++){
        scanf("%lf",&b[i]);
    }
    do{
        sum = 0;
        for(i = 0;i<n;i++){
            for(j = 0;j<n;j++){
                sum += a[i][j]*b[j];
            }
            c[i] = sum;
            sum = 0;
        }
        max = c[0];
        for(i = 1;i<n;i++){
            if(c[i]>max){
                temp = c[i];
                c[i] = max;
                max = temp;
            }
        }
        for(i = 0;i<n;i++){
            c[i] /= max;
        }
        for(i = 0;i<n;i++){
            b[i] = c[i];
        }
        lem++;
    }while(lem!=10);
    printf("\n%lf\n\n",max);
    for(i = 0;i<n;i++){
        printf("%f\n",b[i]);
    }

    return 0;


}