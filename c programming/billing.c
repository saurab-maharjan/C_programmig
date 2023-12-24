#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct product{
	char product[20][20];
	int quantity[20],total[20],net_total,price[20],due,fre;
}product;
typedef struct info{
	char name[50],address[50];
	long long phone;
	product p;
}info;
void add(){
	info *s;
	FILE *fp;
	int n,i,m,j;
	fp = fopen("saurab1.txt","a");
	printf("*******************  welcome to the recording of the customer information  ************************\n");
	printf("\nenter the numbers of customer you want to record the information\n");
	scanf("%d",&n);
	s = (info *)calloc(n,sizeof(info));
	for(i=0;i<n;i++){
		getchar();
		printf("enter the name of customer %d\n",i+1);
		scanf("%[^\n]s",s[i].name);
		getchar();
		printf("enter the address of customer %d\n",i+1);
		scanf("%[^\n]s",s[i].address);
		getchar();
		printf("enter the phone number of customer %d\n",i+1);
		scanf("%lld",&s[i].phone);
		getchar();
		printf("enter the number of product\n");
		scanf("%d",&m);
		s[i].p.fre = m;
		s[i].p.net_total = 0;
		getchar();
		for(j=0;j<m;j++){
			printf("enter the name of product %d\n",j+1);
			scanf("%[^\n]s",s[i].p.product[j]);
			getchar();
			printf("enter the quantity of product %d\n",j+1);
			scanf("%d",&s[i].p.quantity[j]);
			getchar();
			printf("enter the price of product %d\n",j+1);
			scanf("%d",&s[i].p.price[j]);
			getchar();
			s[i].p.total[j] = s[i].p.price[j] * s[i].p.quantity[j];
			s[i].p.net_total += s[i].p.total[j];
			
		}
		s[i].p.due = s[i].p.net_total;
		fwrite(&s[i],sizeof(info),1,fp);
		
	}
	printf("**************************  successfully recorded****************************\n");
	fclose(fp);
}
void bill(){
	FILE *fp;
	int n,i,p=0,j;
	info *s,s1;
	char name[50];
	fp = fopen("saurab1.txt","r");
	fseek(fp,0,SEEK_END);
	n = ftell(fp)/sizeof(info);
	s = (info*)calloc(n,sizeof(info));
	rewind(fp);
	for(i=0;i<n;i++){
		fread(&s[i],sizeof(info),1,fp);
	}
	fclose(fp);
	getchar();
	printf("enter the name of customer to see the voucher\n");
	scanf("%[^\n]s",name);
	for(j=0;j<n;j++){
		
			if(strcmp(s[j].name,name)==0){
				printf("*****************  welcome to voucher of the customer  ************************\n");
            printf("Name               : %s\n",s[j].name);
            printf("Address            : %s\n",s[j].address);
            printf("phone number       : %lld\n",s[j].phone);
            printf("-----------------------------------------------------------------\n");
            printf("Product name             quantity             price             total\n");
            printf("-----------------------------------------------------------------\n");
            for(i=0;i<s[j].p.fre;i++){
         	printf("%s                       ",s[j].p.product[i]);
         	printf("%d                      ",s[j].p.quantity[i]);
         	printf("%d                    ",s[j].p.price[i]);
         	printf("%d                     \n",s[j].p.total[i]);
         	
        	}
        	printf("Net total           : %d\n",s[j].p.net_total);
        	printf("Total due            : %d\n",s[j].p.due);
			}
		
	}
   fclose(fp);
	
	
}
void payment(){
	FILE *fp,*fp1;
	int n,i,p=0,j=0,pay;
	info *s,s1;
	char name[50];
	fp = fopen("saurab1.txt","r");
	fp1 = fopen("saurab11.txt","w");
	fseek(fp,0,SEEK_END);
	n = ftell(fp)/sizeof(info);
	s = (info*)calloc(n,sizeof(info));
	rewind(fp);
	printf("enter the name of customer for payment\n");
	getchar();
	scanf("%[^\n]s",name);
	while(fread(&s1,sizeof(info),1,fp)==1){
		
		if(strcmp(name,s1.name)==0){
			printf("welcome %s for payment\n",name);
			if(s1.p.due!=0){
			printf("enter the amount you want to pay\n");
          	scanf("%d",&pay);
          	if(pay==s1.p.due){
          		s1.p.due = 0;
          		printf("congratulation %s your due is clear\n",name);
			  }
			 else if(pay>s1.p.due){
			 	printf("congratulation %s your due is cleared\n",name);
			 	printf("your return amount is : %d\n",pay-s1.p.due);
			 	s1.p.due = 0;
			 } 
			 else{
			 	s1.p.due = s1.p.due - pay;
			 	printf("your due amount is %d\n",s1.p.due);
			 }	
			}
			else{
				printf("your due is already cleared\n");
			}
        	
		
		
		}
		
			fwrite(&s1,sizeof(info),1,fp1);
			j++;
	}
	fclose(fp);
	fclose(fp1);
	remove("saurab1.txt");
	rename("saurab11.txt","saurab1.txt");
	
	
}
void due(){
	FILE *fp;
	int n,i=0,p=0,j;
	info *s,s1;
	char name[50];
	fp = fopen("saurab1.txt","r");
	fseek(fp,0,SEEK_END);
	n = ftell(fp)/sizeof(info);
	s = (info*)calloc(n,sizeof(info));
	rewind(fp);
	while(fread(&s[i],sizeof(info),1,fp)==1){
		i++;
	}
	
	fclose(fp);
	printf("enter the name of customer to see the due amount\n");
	getchar();
	scanf("%[^\n]s",name);
	for(i=0;i<n;i++){
		if(strcmp(name,s[i].name)==0){
			printf("****************welcome %s for your due amount********************\n",s[i].name);
			printf("Your due amount is : %d\n",s[i].p.due);
			
		}
	}
}
void main(){
	int n;
	while(1){
		printf("1 to add\n");
		printf("2 to display bill\n");
		printf("3 to payment\n");
		printf("4 to display due\n");
		printf("5 to exit\n");
		printf("\n\nenter your choice\n");
		scanf("%d",&n);
		switch(n){
			case 1 :
				system("CLS");
				add();
				break;
			case 2 :
				system("CLS");
				bill();
				break;
			case 3 :
				system("CLS");
				payment();
				break;
			case 4 :
				system("CLS");
				due();
				break;		
			case 5 :
				exit(1);
				break;	
			default:
			  printf("sorry i don't understand\n");					
		}
	}
}
