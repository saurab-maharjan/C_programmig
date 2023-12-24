#include<stdio.h>
#include<math.h>

float fun(float a, float b , float c,float m,float n, float p){
    return((p*a - n*b - m*c));
}

int main(){
    int i , j ;
    float k[5],l[5],x[4],y[4],z[4],h,a,b,c,d,sl= 0,sk = 0,m,n,p;
    printf(" y'' + my' ny = px\n");
    printf("Enter the value of m,n,p\n");
    scanf("%f%f%f",&m,&n,&p);
    printf("Enter the initial value of x \n");
    scanf("%f",&x[1]);
    printf("Enter the initial value of y \n");
    scanf("%f",&y[1]);
    printf("Enter the initial value of y' \n");
    scanf("%f",&z[1]);
    printf("Enter the of h \n");
    scanf("%f",&h);
        
    for(j = 1;j<=2;j++){
        k[1] = h*z[j];
        l[1] = h*fun(x[j],y[j],z[j],m,n,p);
        printf("k[1] =  %f\n",k[j]);
        printf("l[1] =  %f\n",l[j]);

        for(i = 1;i<=3;i++){

            
            if(i==3){
                a = x[j] + h;
                b = y[j] + k[i];
                c = z[j] + l[i];
                k[i+1] = h*c;
                l[i+1] = h*fun(a,b,c,m,n,p);
            }
            else{
                a = x[j] + h/2;
                b = y[j] + k[i]/2;
                c = z[j] + l[i]/2;
                k[i+1] = h*c;
                l[i+1] = h*fun(a,b,c,m,n,p);
            }
            printf("k[%d] =  %f\n",i+1,k[i+1]);
            printf("l[%d] =  %f\n",i+1,l[i+1]);
        }
        for(i = 1;i<=4;i++){
            if(i==1||i==4){
                sl += l[i];
                sk += k[i];
            }
            else{
                sl += 2*l[i];
                sk += 2*k[i];
            }
        }
        sl /= 6;
        sk /= 6;
        printf("sk = %f\n",sk);
        printf("sl = %f\n",sl);
        y[j+1] = y[j] + sk;
        z[j+1] = z[j] + sl;
        x[j+1] = x[j] + 0.5;
        printf("y[%d] = %f\n",j+1,y[j+1]);
        printf("z[%d] = %f\n",j+1,z[j+1]);
        printf("\n");
    }
    


    return 0;

}