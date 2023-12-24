#include<stdio.h>
#include<math.h>

float fun(float n){
    return(sin(n) );
}

int main(){
    float up ,lw,h,sum = 0,res,x,y;
    int n, i,j;
    printf("Enter the upper limit\n");
    scanf("%f",&up);
    printf("Enter the lower limit\n");
    scanf("%f",&lw);
    printf("Enter the number of sub intervals \n");
    scanf("%d",&n);
    h = (up-lw)/n;
    printf("h = %f\n",h);
    sum = fun(lw) + fun(up);
    printf("yo + y6 = %f\n",sum);
    for(i = 1;i<=n-1;i++){
        x = (lw + (i*h));
        sum += 2*fun(x);
        printf("x %d = %f\n",i,x);
        printf("y %d = %f\n",i,fun(x));
        
    }
    res = (h*sum)/2;
    printf("The result is %f\n",res);
    return 0;
}