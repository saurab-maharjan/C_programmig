#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fun1(float a ){
    return a - exp(-a);
}

float fun2(float b){
    return 1 + exp(-b);
}
int main(){
    float x ,c;
    int count = 0;
    printf("Enter the initial point \n");
    scanf("%f",&x);
    do{
        count++;
        if(fun2(x)<=0.000005){
            printf("There is no root \n");
            exit(0);
        }
        if(count == 200){
            printf("There is no root \n");
            exit(0);
        }
        c = x - fun1(x)/fun2(x);
        x = c;
    }while(fun1(c)>=0.000005);
    printf("The root of the equation is %f ", c);
    return 0;
}