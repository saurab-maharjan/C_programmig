#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    float x[6] = {1,2,3,4,5,6} , y[6] = {5.5,6.5,9.4,15.2,30.6,49.8},sumx = 0,sumy = 0,sumxx = 0,sumxy = 0,a,b;
    int i ;
    for(i = 0;i<6;i++){
        sumx += x[i];
        sumxx += x[i]*x[i];
        sumxy += x[i]*log(y[i]);
        sumy += log(y[i]);
    }
    a = (sumy*sumxx - sumx*sumxy)/(6*sumxx - sumx*sumx);
    b = (6*sumxy - sumy*sumx)/(6*sumxx - sumx*sumx);
    printf("a = %f , b = %f ", exp(a) , b);
    return 0;

}