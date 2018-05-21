/* Daniel Powley
Assignment 5, abundant numbers
October 1, 2015*/

#include <stdio.h>

int main(){

	int num,i,j,total=0,good;
	FILE *ifp;

	/*scans input document*/
	ifp = fopen("input.txt", "r");
		fscanf(ifp, "%d", &num); /*scans for number of inputs*/
		
		/*declares the array with the number of elements equal to the first line scanned in*/
		int testNum[num];

        /*Scans for the inputs and puts them into the array */
		for(i=0; i<num; i++)
		fscanf(ifp, "%d", &testNum[i]);
		fclose(ifp);

	/* If the document is unable to be read, do not run the program*/
	if(fopen("input.txt", "r")==NULL){
		printf("Unable to read");
	}
	else{
		/* Tests all the numbers in the array*/
		for(i=0; i<num; i++){
            /* Tests the number against the requisite conditions, but never tests the number against itself nor 0*/
			for(j=1; j<testNum[i]; j++){
				/* Each proper divisor is added together and assigned a variable*/
				if(testNum[i]%j == 0){
                        total += j;
                }
            }
            
            /*If the total of the divisors is greater than the number being tested, it is abundant*/
			if (total>testNum[i])
                printf("Test case #%d: %d is abundant.\n", i+1, testNum[i]);
                
            else
                printf("Test case #%d: %d is NOT abundant.\n", i+1, testNum[i]);
			/*Variable "total" is reset to 0 in either case, because at the end of the loop, it still retains the total value of the proper divisors*/
			total = 0;
		}
	}
	return 0;
}
