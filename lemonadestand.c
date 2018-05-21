/* Daniel Powley
Lemonade Stand assignment
September 4 2015 */

#include <stdio.h>
#define COOKIE_PRICE .50
#define LEM_PRICE .75

int main(){
	int numCookies, numLem;
	float cookieTotal, lemTotal, sumTotal, dollarOnHand, cashBack;
	printf("Welcome to the Sunny Lane Lemonade Stand\n\n");
	printf("How many cookies would you like?\n\n");
	scanf("%d", &numCookies);
	printf ("\nHow many lemonades would you like?\n\n");
	scanf("%d", &numLem);
	cookieTotal = numCookies * COOKIE_PRICE;
	lemTotal = numLem * LEM_PRICE;
	sumTotal = cookieTotal + lemTotal;
	printf("\nThat will cost $%.2f\n\n", sumTotal);
	printf("How much money do you have?\n\n");
	scanf ("%f", &dollarOnHand);
	cashBack = dollarOnHand - sumTotal;
	printf("\nThat is $%.2f change.\n\n\n", cashBack);
	printf("Thank You.");
	
return 0;
}
