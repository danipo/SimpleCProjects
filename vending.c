#include <stdio.h>

int main(){
	float coke=2, sprite=1.50, fanta=2, total;
	int deposit, choice;
	
	printf("Welcome! Please type your deposit!\n");
	scanf("%d", &deposit);
do{	
	printf("Please make a selection. 1=Coke. 2=Sprite. 3=Fanta. 4=exit\n");
	scanf("%d", &choice);
switch(choice){
	case 1:
		printf("You have selected a Coke!\n");
		total = deposit-coke;
		printf("Your change is $%.2f\n", total);
		break;
	case 2:
		printf("You have selected a Sprite!\n");
		total = deposit-sprite;
		printf("Your change is $%.2f\n", total);
		break;
	case 3:
		printf("You have selected a Fanta!\n");
		total = deposit-fanta;
		printf("Your change is $%.2f\n", total);
		break;
	case 4:
		break;
	default:
		printf("You need to make a choice 1-3\n");		
}
}while(choice!=4);
printf("Thank you!");

return 0;
}
