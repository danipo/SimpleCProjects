/* Daniel Powley
Assignment 7, banking
October 23 2015*/

#include <stdio.h>

/*Withdraws money from the account*/
float withdraw(float withBal, float withAmt){
	float a;
	/*If there is not enough money in the account to withdraw.*/
	if(withBal<withAmt)
		printf("Cannot withdraw. Insufficent funds.");

	/*Else subtract the necessary funds from the account*/
	else
		a = withBal - withAmt;

	return a;
}

/*--------------------------------------------------------------*/

/*Deposits money into the account*/
float deposit(float depBal, float depAmt){
	float bal=0;
	/*If the balance has a negative amount*/
	if(depBal<0)
		printf("Error. Invalid amount.");

	/*Else add the funds to the account*/
	else
		bal = depBal + depAmt;

	return bal;
}

/*--------------------------------------------------------------*/

/*Add interest to the account*/
float update(float upBalance){
	float bal=0;

	/*If the balance has a negative amount*/
	if(upBalance<0)
		printf("Error. Invalid amount.");

	/*Else generate the balance of the account plus interest*/
	else
		bal = upBalance + upBalance*1.85/100;

	return bal;
}

/*-------------------------------------------------------*/

/*runs the rest of the functions*/
float processServices(FILE *ifp, int account, float balance){

	char currOp;
	int accNum;
	float amt, output;
	float getBalance(int, int, float);
		
		do{
			fscanf(ifp,"%c", &currOp);
	        if(currOp = 'W'){
				fscanf(ifp,"%d %f", &accNum, &amt);
				if(accNum == account)
				output = withdraw(balance, amt);
			}
			else if(currOp = 'D'){
				fscanf(ifp,"%d %f", &accNum, &amt);
				if(accNum == account)
				output = deposit(balance, amt);
			}
			else if(currOp = 'U'){
				fscanf(ifp,"%d", &accNum);
				if(accNum == account)
				output = update(balance);
			}
			else if(currOp = 'B'){
				fscanf(ifp,"%d", &accNum);
				if(accNum == account)
				output = getBalance(accNum, account, balance);
			}
			else
				printf("Sorry, could not complete this operation");
		
		}while(currOp !='Z');
		
		return output;
}

/*---------------------------------------------------------------*/

/* Get the balance of the account*/
float getBalance(int acc, int account, float balance){
	float a;

	a = balance;

	return a;
}


/*--------------------------------------------------------------*/

int main(){

	FILE *ifp;
	int i, numAccounts;
	float output;
	
	ifp = fopen("bankfile.txt.", "r");

	if(fopen("bankfile.txt", "r") == NULL)
		printf("Sorry, was not able to get that file");

	else{
		printf("Account\t\tBalance\n");
	printf("-----------------------\n");

		/* Scans for the number of bank accounts*/
		fscanf(ifp, "%d", &numAccounts);
		int acc[numAccounts];
		float balance[numAccounts];

		/* Scans the account number and the money in the account*/
		for(i=0; i<numAccounts; i++){
			fscanf(ifp, "%d %f", &acc[i], &balance[i]);
			printf("%d %.2f\n", acc[i], balance[i]);
		    output = processServices(ifp, acc[i], balance[i]);
		    printf("%d\t\t%.2f\n", acc[i], output);
		}
	}
	fclose(ifp);
	return 0;
}


