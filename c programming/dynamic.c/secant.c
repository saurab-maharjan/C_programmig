#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float fun(float a){
    return (3*a + sin(a) - exp(a) );
}
int main(){
    float a , b , c;
    int count = 0 ;
    printf("Enter the interval ");
    scanf("%f%f",&a,&b);
    do{ 
        count ++;
        if(fabs(fun(a)-fun(b))<=0.00000005){
            printf("There is no root ");
            exit(0);
        }
        c = (a*fun(b) - b*fun(a))/(fun(b) - fun(a));
        a = b;
        b = c;
        if(count==800){
            printf("There is no root in the given interval ");
            exit(0);
        }

    }while(fabs(fun(c))<=0.00000005);
    printf("The root of the equation is %f ",c);
    return 0;
}