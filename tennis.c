/* Daniel Powley
Assignment 9, Tennis
November 18, 2015*/

#include <stdio.h>

int main(){
	
	FILE *ifp;
	int a[12][8];
	int i,j, option;
	
	/* prototypes for the menu and request processing functions*/
	void displayMenu();
	void processRequest(int[][8], int);
	void makeArray(FILE*, int[][8]);
	
	ifp = fopen("scores.txt", "r");
	
	if(fopen!=NULL){
	
	/*creates array*/
	makeArray(ifp, a);

	/*While the option chosen is not 0, the service request function is run*/
	do{
		displayMenu();
		scanf("%d", &option);
		printf("\n");
		processRequest(a, option);	
	}while(option!=0);
	}
	
	else
		printf("Sorry, File could not be found!");
	
	fclose(ifp);	
	return 0;	
}
//-------------------------------------------------------//

/* Funtion for the menu */ 
void displayMenu(){
	
	printf("Select from options 1-7 or 0 to stop.\n1. To get a score for a specific game.\n");
	printf("2. To get the max score for a specific month.\n3. To get the average score for a specific month.\n");
	printf("4. To the max score for the year.\n5. To get the average score for the year.\n");
	printf("6. To get all the tournaments missed for the year.\n7. To print all scores for the year.\n");
	printf("0. To exit.\n\n");
	
}
//-----------------------------------------------------//

/*Funtion to process request. The option is passed through and from here, other funtions are run based on the selection*/
void processRequest(int a[][8], int option){
	
	int i,j;
	/* Prototypes for the other functions, giving different results*/
	int getScore(int[][8], int, int);
	int getMonthMax(int[][8], int);
	float getMonthAvg(int[][8], int);
	int getYearMax(int[][8]);
	float getYearAvg(int[][8]);
	int toursMissed(int[][8]);
	void printArray(int[][8]);
	
	/*Runs a different function for each choice*/
	switch(option){
			case 1: 
				printf("What month and tournament number do you want?\n");
				scanf("%d %d", &i, &j);
				printf("The result of tournament %d is %d\n\n", j, getScore(a,i,j));
				break;
			case 2: 
				printf("What month do you want?\n");
				scanf("%d", &i);
				printf("The max score for month %d is %d\n\n", i, getMonthMax(a,i));
				break;
			case 3: 
				printf("What month do you want?\n");
				scanf("%d", &i);
				printf("The average for month %d is %.2f\n\n", i, getMonthAvg(a,i));
				break;
			case 4: 
				printf("The max score for the year is %d\n\n", getYearMax(a));
				break;
			case 5: 
				printf("The average for the year is %.2f\n\n", getYearAvg(a));
				break;
			case 6: 
				printf("The number of tournaments missed for the year is %d\n\n", toursMissed(a));
				break;
			case 7: printArray(a);
				break;
			case 0: 
				printf("Thank you! Goodbye!");
				break;
			default: printf("Please make a valid choice.\n");
											
		}
}
//-----------------------------------------------------//

void makeArray(FILE *ifp, int a[][8]){
	int i,j;
	
/*Scans numbers and puts them into a 2D array
Since there can never be more than 12 months and 8 games, the array is of a constant length*/
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			fscanf(ifp,"%d", &a[i][j]);
		}
	}
	
}

/* function to find score of a specific game*/
int getScore(int a[][8], int i, int j){
	
	return a[i-1][j-1];
}
//---------------------------------------------------//

/*Function to get maximum score from a scanned month*/
int getMonthMax(int a[][8], int month){
	int i;
	int max=0;
	
	for(i=0;i<8;i++){
		if(a[month-1][i]>max)
		max = a[month-1][i];
	}
	
	return max;	
}
//----------------------------------------------------------//

/*Function to get the average score from a scanned month*/
float getMonthAvg(int a[][8], int month){
	int i;
	int sum=0;
	float avg;
	
	for(i=0; i<8; i++){
		sum += a[i][month-1];
	}
	avg = sum/8.0;
	
	return avg;
}
//-------------------------------------------------//

/*Function to get the maximum score from the array*/
int getYearMax(int a[][8]){
	int i,j; 
	int max = 0;
	
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			if(a[i][j]>max)
			max = a[i][j];
		}
	}
	
	return max;
}
//----------------------------------------------------------//

/*Function to get the average score for the array*/
float getYearAvg(int a[][8]){
	int i,j; 
	int sum=0;
	float avg;
	
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			sum += a[i][j];
		}
	}
	
	avg = sum/96.0;
	
	return avg;
}
//----------------------------------------------------------//

/* Funtion to find the number of 0 scores in the array*/
int toursMissed(int a[][8]){
	int i,j, count = 0;
	
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			if(a[i][j]==0)
			count++;
		}
	}
	
	return count;
}
//---------------------------------------------------------//

/*Prints the array*/
void printArray(int a[][8]){
	int i,j;
	
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			printf("%d\t", a[i][j]);
		}
	printf("\n");	
	}
	printf("\n\n");
}
