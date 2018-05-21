/* Daniel Powley
Assignment 8, Pass by Reference
October 30, 2015*/

#include <stdio.h>
#include <stdlib.h>

/*Length can never be longer than 20*/
#define LEN 20

/*Prints the values of the array*/
void printArray(FILE *opt, int array[], int counter){
	int i;
	fprintf(opt,"The original array is: ");
	for (i=0;i<counter;i++){
		fprintf(opt,"%d ", array[i]);
	}
	fprintf(opt,"\n\n");
}

/*------------------------------------*/
/* Finds the max value of the Array*/
void getMax(FILE *opt, int array[], int counter){
	int max=0, i;

	for(i=0;i<counter;i++){
		if(array[i]>max)
			max = array[i];
	}

	fprintf(opt,"The maximum value is %d\n\n", max);
}

/*------------------------------------*/
/* Finds the minimum value of the array*/
void getMin(FILE *opt, int array[], int counter){
	int min=99999, i;

	for(i=0;i<counter;i++){
		if(array[i]<min)
		min = array[i];
	}

	fprintf(opt,"The minimum value is %d\n\n", min);
}

/*------------------------------------*/
/*Sorts the numbers, lowest to highest*/
void getSort(FILE *opt, int array[], int counter){
fprintf(opt,"The sorted array is: ");
    int i,j, temp;

    for(i=0;i<counter;i++){
        for(j=i+1;j<counter;j++){
            if(array[i]>array[j]){ /*Checks to see if the first number is higher than the next*/
			temp = array[i]; /*If so, then the number is placed into temp*/
			array[i]=array[j]; /*The second number is then swapped with the first*/
			array[j]=temp;
            }
        }
        }
	for(i=0;i<counter;i++){
    fprintf(opt,"%d ", array[i]);
    }

	fprintf(opt,"\n\n");
}

/*------------------------------------*/
/* Adds the numbers*/
void getSum(FILE *opt, int array[], int counter){
	int sum=0, i;

	for(i=0;i<counter;i++){
		sum += array[i];
	}
	fprintf(opt,"The total of the values in the array is %d", sum);
}

/*-----------------------------------*/
int main(){

	FILE *ipt, *opt;

	int array[LEN];
	int counter = 0;

	ipt = fopen("input.txt", "r");
	opt = fopen("output.txt", "w");
	
	/* Checks to see if the file will open*/
	if(fopen("input.txt","r")==NULL)
		printf("Sorry, could not open file");

	else{
		
		int i=0;
		
		/*loop scans and adds forever until a zero is scanned, then breaks the loop*/
		while(1){
			fscanf(ipt,"%d", &array[i]);
			if(array[i]==0)
			break;
			counter++;
			i++;
				
		}	
		
		/*After the array is created, then run the other functions*/
		printArray(opt, array, counter);
		getMax(opt, array, counter);
		getMin(opt, array, counter);
		getSort(opt, array, counter);
		getSum(opt, array, counter);
	}

	fclose(ipt);
	fclose(opt);
	return 0;
}

