#include <stdio.h>

int main(){
	
	int num, i;
	
	printf("How many numbers do we have?\n");
	scanf("%d", &num);
	
	int numbers[num];
	
	printf("What are the numbers?\n");
	for(i=0;i<num;i++){
	scanf("%d", &numbers[i]);
	}
	
	printf("Which number are you asking for?\n");
	scanf("%d", &input);
	
	printf("%d", numbers[input-1]);
	
	if input%2==0;
		printf("Number is even!");
	else
		printf("Number is odd!");
			
	return 0;
}
