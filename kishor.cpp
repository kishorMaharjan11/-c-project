
#include<stdio.h>
#include<string.h>
#include<time.h>
#define Files_data "billing.txt"

int main(){
	time_t t;
	time(&t);
	char name[100];
	int quantity,items,numberPerson;
	char custumer[100];
	float Total,perPerson=0;
	int price = 0;
	float GrandTotal,discount,vat,tips;
	
		printf("1.momo = Rs100");
		printf("\n2.noodels = Rs150");
		printf("\n3.panipuri = Rs50");
		printf("\n4.laghing = Rs60");
		printf("\n5.pizza = Rs450");
		printf("\n6.coke = Rs50");
		printf("\n7.Chicken = Rs500");
		printf("\n8.chatpate = Rs100");
		printf("\n9.aalupuri = Rs150");
		
		printf("\n\nIf you get over than Rs 3000 you get a dicount of 5 percent on it");
		
	printf("\n\n\nname of the costumer:");
	fgets(custumer,sizeof(custumer),stdin);
	
		printf("Number of Person:");
		scanf("%d",&numberPerson);
		
		printf("quantity of items:");
	scanf("%d",&quantity);
	    printf("Tips: ");
	    scanf("%f",&tips);
	
	for(int i=1; i<=quantity; i++){
	    printf("item orderd :");
	    scanf("%d",&items);
	
	
	switch(items){
		case 1:
			price += 100;
			break;
			
			case 2:
				price += 150;
				break;
			case 3:
				price +=50;
				break;
				
		    case 4:
		    	price += 60;
		    	break;
		    case 5:
		    	price += 450;
		    	break;
		    	
		    case 6:
		    	price += 50;
		    	break;  
		    case 7:
		    	price += 500;
		    	break;
		    case 8:
		    	price += 100;
		    	break;
		    	case 9:
		    	price += 150;
		    	break;
		    default :
		    	price +=0;
		    	
	}
	}
	
	Total += price;
	vat = (Total*13)/100;
	if(Total == 3000){
	    discount = (Total*5)/100;
	}else{
		
		
		
		
		
		
	    discount = 0;
	}
	
	
	 
	GrandTotal = Total + vat - discount + tips;
perPerson = GrandTotal/numberPerson;
printf("\n\n-----------------------------------------------------------");
printf("\n\n\t\t\t Bill's of %s",custumer);
printf("\n\t\t\t%s",ctime(&t));
printf("\nTotal Amount = %.2f",Total);

printf("\nvat = %.2f",vat);

printf("\ntips = %.2f",tips);

printf("\nDisount Amount = %.2f",discount);

printf("\nGrand Total Amount = %.2f",GrandTotal);

printf("\nPer person amount = %.2f",perPerson);
printf("\n------------------------------------------------------");

FILE*fp = fopen(Files_data,"a");
if (fp!=NULL){


fprintf(fp,"\n\n\t\t\t Bill's of %s",custumer);
fprintf(fp,"\n\t\t\t%s",ctime(&t));
fprintf(fp,"\nTotal Amount = %.2f",Total);

fprintf(fp,"\nvat = %.2f",vat);
fprintf(fp,"\nTips = %.2f",tips);

fprintf(fp,"\nDisount Amount = %2.f",discount);

fprintf(fp,"\nGrand Total Amount = %.2f",GrandTotal);


fprintf(fp,"\nPer person amount = %.2f",perPerson);

fprintf(fp,"\n------------------------------------------------------");
fclose(fp);
}
return 0;
}
