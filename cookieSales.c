/* Daniel Powley
COP 3223 Section 5
Assignment 10, Cookie Sales
November 25, 2015 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Creates a struct of the customer's information
struct order{
	char firstName[20];
	char lastName[20];
	char type[10];
	int num;
	float price;
	char paid;
};

//---------------------------------------//
int main(){
	
	FILE *ifp, *opt; 
	int i, numAccounts;
	
	//function prototypes
	void fillStructs(FILE*, int, struct order[]);
	void printStruct(FILE*, int, struct order[]);
	float received(int, struct order[]);
	int notPaid(int, struct order[]);
	float outstanding(int, struct order[]);
	float perOut(int, struct order[]);
	
	ifp= fopen("custInfo.txt", "r");
	opt= fopen("output.txt", "w");
	
	//if the file can be opened
	if(fopen!=NULL){
		fscanf(ifp,"%d", &numAccounts);
		
	//declares a structs for each customer, to be filled by the fillStructs function
	struct order cust[numAccounts];
	
		//first the program scans the information into a struct and prints it, then uses the data to calculate the different fields for output
		fillStructs(ifp, numAccounts, cust);
		printStruct(opt, numAccounts, cust);
		fprintf(opt,"\nSummary\n--------------\n\n");
		fprintf(opt,"Total cash received: $%.2f\n", received(numAccounts, cust));
		fprintf(opt,"Num customers who have not paid: %d\n", notPaid(numAccounts, cust));
		fprintf(opt,"Total amount outstanding: $%.2f\n", outstanding(numAccounts, cust));
		fprintf(opt,"Percentage of sales outstanding: %.0f%%\n", perOut(numAccounts, cust));
	}
	
	//if the file cannot be opened
	else
		printf("File could not be opened!");
		
	fclose(ifp);
	fclose(opt);
	return 0;
}
//-------------------------------------//

//scans the input file for the necessary information to fill each struct created in main
void fillStructs(FILE *ifp, int numAccounts, struct order cust[] ){
	int i;
	
	for(i=0;i<numAccounts;i++){
		fscanf(ifp, "%s %s %s %d %f %c", cust[i].firstName, cust[i].lastName, cust[i].type, &cust[i].num, &cust[i].price, &cust[i].paid);
	}
}
//------------------------------------//

//prints out the information gathered from the structs
void printStruct(FILE *opt, int numAccounts, struct order cust[]){
	int i;
	
	fprintf(opt,"Customers\n-------------\n\n");
	fprintf(opt,"Name\t\tType of Cookie\tNum of Boxes\tCost of Box\tPaid\n");
	fprintf(opt,"-----------------------------------------------------------------------\n");
	for(i=0; i<numAccounts; i++){
		fprintf(opt,"%s %s\t%s\t\t%d\t\t%.2f\t\t%c\n", cust[i].firstName, cust[i].lastName, cust[i].type, cust[i].num, cust[i].price, cust[i].paid);
	}
	
}
//------------------------------------//

//finds the amount that has been paid so far
float received(int numAccounts, struct order cust[]){
	float sum = 0;
	int i;
	
	//if the customer's payment has been received, return the total amount that has been gathered
	for(i=0;i<numAccounts;i++){
		if(cust[i].paid == 'Y')
		sum += cust[i].price * cust[i].num;
	}
	
	return sum;
}
//------------------------------------//

//finds the number of customers who have not paid
int notPaid(int numAccounts, struct order cust[]){
	int i, notPaid = 0;
	
	//if the customer has not paid, count those customers
	for(i=0; i<numAccounts; i++){
		if(cust[i].paid == 'N')
		notPaid++;
	}
	
	return notPaid;
}
//------------------------------------//

//finds the amount that has not been paid yet
float outstanding(int numAccounts, struct order cust[]){
	int i;
	float amt=0;
	
	for(i=0;i<numAccounts;i++){
		if(cust[i].paid == 'N'){
			amt += cust[i].price * cust[i].num;
		}
	}
	
	return amt;
}
//----------------------------------//

//finds the percentage of money that has not been received to the amount that has
float perOut(int numAccounts, struct order cust[]){
	int i, count=0;
	float totalReceived=0, owed=0, per;
	
	for(i=0;i<numAccounts;i++){
		if(cust[i].paid == 'Y')
		totalReceived += cust[i].price * cust[i].num; //If the customer has paid, it goes to this variable
		else if(cust[i].paid == 'N')
		owed += cust[i].price * cust[i].num;  //if not, it goes to this one
	}
	per = owed/totalReceived*100;
	
	return per;
}
