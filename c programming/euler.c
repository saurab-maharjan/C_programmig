#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fun1(float x , float y){
    return(x+y);
}
float fun2(float x , float y){
    return(x*x+y);
}
float fun3(float x , float y){
    return(x*x +2*x -y);
}
void euler(float x , float y , float h , float xn){
    while(x<xn){
        x+= h;
        y+= h*fun3(x,y);
        printf("  %f , %f \n",x,y);
    }
}
void rk2(float x , float y , float h , float xn){
    float k1 , k , k2;
    while(x<xn){
        k1 = h*fun3(x,y);
        k2 = h*fun3(x+h,y+k1);
        k = (k1+k2)/2;
        y += k;
        x+= h;
        printf(" %f , %f \n",x,y);
    }
}
void rk4(float x , float y , float h , float xn){
    float k1 , k , k2,k3,k4;
    while(x<xn){
        k1 = h*fun3(x,y);
        k2 = h*fun3(x+h/2,y+k1/2);
        k3 = h*fun3(x+h/2 , y+k2/2);
        k4 = h*fun3(x+h , y+k3);
        k = (k1+2*k2+2*k3+k4)/6;
        y += k;
        x+= h;
        printf(" %f , %f \n",x,y);
    }
}

int main(){
    float x , y, xn, h;
    printf("Enter the intial value of x , y , h , xn  : ");
    scanf("%f%f%f%f",&x,&y,&h,&xn);
    rk4(x,y,h,xn);
    return 0;
}