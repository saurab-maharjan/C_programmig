#include<stdio.h>
int fun(int n){
    static int  m;
    m = n;
    if(m==1){
        return m;
    }
    else{
        m = n*fun(n-1);
    }
}
int main(){

    int p ;
    p = fun(5);
    printf("%d\t",p);
    return 0;
}