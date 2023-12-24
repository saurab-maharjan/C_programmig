#include<stdio.h>
#include<math.h>
float fun(float n){
    return (n*sin(n)+cos(n));
}
int main(){
    float a , b , c;
    int count = 0;
    printf("Enter the interval\n");
    scanf("%f%f",&a , &b);
    if(fun(a)*fun(b)>0){
        printf("sorry there is no root in the given interval \n");
    }
    else{
        do{ count++;
            c = (a+b)/2;
            if(fun(a)*fun(c)>0){
                a = c;
            }
            else{
                b = c;
            }

        }while(c<=0.000000001);
        printf("root of given equation is %f\n",c);
    }
    
    printf("count = %d", count);
    return 0;

}