/*You have two parties to attend. You bring n slices of pizza to the first party. 
You give out as many pieces to each of the attendees (except yourself) so that each receives 
an equal number of pieces. You then take the leftover pieces to the second party and repeat this process. 
The pieces leftover from this second party are the ones you actually get to eat. */


#include <stdio.h>

int main() {
int slices, party1, party2;
printf("How many slices of pizza did you start with?\n");
scanf("%d", &slices);
printf("How many people were at the first party?\n");
scanf("%d", &party1);
printf("How many people were at the second party?\n");
scanf("%d", &party2);

slices = (slices%party1)%party2;

printf("You end up with %d slices for yourself.\n", slices);


return 0;

}
