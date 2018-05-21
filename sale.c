/* Daniel Powley
sale.c program
August 30th, 2015 */

#include <stdio.h>

int main(){
    int price;
    int salePercent;
    int finalPrice;
    printf ("What is the original price?\n\n");
    scanf ("%d", &price);
    printf ("\nWhat is the sale percentage? \n\n");
    scanf ("%d", &salePercent);
    finalPrice = price - (price * salePercent/100);
    printf("\nThe final price of a product that costs $%d with a sale percentage of %d is $%d", price, salePercent, finalPrice);
return 0;
}
