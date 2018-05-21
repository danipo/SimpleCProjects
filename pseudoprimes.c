#include <stdio.h>

int main() {
printf("Here are Arup pseudoprimes between 1 and 10000:\n ");
int i,j;
for (i=1; i<=10000; i++) {
    //check if i is prime or not
    int isprime=1;
    for(j=2;j<i;j++){
        if(i%j == 0)
            isprime = 0;
    }
    if(i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0 && isprime == 0)
        printf("%d ", i);
}
return 0;
}
