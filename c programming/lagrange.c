#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int i , j , k , n;
    double xn;
    printf("Enter the number of data : ");
    scanf("%d",&n);
    printf("Enter the domain to find its best approximation value ");
    scanf("%lf",&xn);
    double x[n] , y[n]    ;
    for(i = 0;i<n;i++){                         /* Taking the value of x and its corresponding functional value */
        printf("Enter the value of x %d = ",i+1);
        scanf("%lf",&x[i]);
        printf("Enter the value of y %d = ",i+1);
        scanf("%lf",&y[i]);
    }
    double  sum = 0 , up , lw;
    for(i = 0;i<n;i++){
        up = 1;
        lw = 1;
        for(j = 0;j<n;j++){
            if(i == j ){
                j++;
            }
            if((x[i] - x[j])==0){
                printf("Error has occur \n");
                exit(0);
                }
            if(i==n-1 && j == n-1){
                j--;
            }
            up *= (xn - x[j]);
            lw *= (x[i] - x[j]);
            
        }
        sum += (up * y[i]) / (lw);
    }

    printf("%lf\n",sum);
    return 0;
}