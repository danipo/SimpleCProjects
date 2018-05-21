/* Daniel Powley
Assignment 6, Elections
October 22, 2015*/

#include <stdio.h>

int main (){

FILE *ifp;
int parties, states,i,j,k, max, temp, stateNumber=1;


	ifp = fopen("votes.txt", "r");

    /* If the file is not found, the program will not run*/
if(fopen("votes.txt","r")==NULL)
		printf("File could not open!");

else{
		fscanf(ifp, "%d", &parties);
		fscanf(ifp, "%d", &states);

	int votes[parties][states];

    /* Generates the array of all the votes*/
	for (i=0; i<parties; i++){
		for (j=0; j<states; j++){
			fscanf(ifp,"%d", &votes[i][j]);
		}
	}
	
	printf("\n");

	int highest;
	int total[parties];
	char pLetter[10]= {'A','B','C','D','E','F','G','H','I','J'};

    /*Creates an array to store the values of each winning state*/
    for(i=0;i<parties;i++){
        total[i]=0;
    }

    printf("Election Results\n-----------------------------\n");
    /* Scans the results of each state (column)*/
	for(i=0;i<states;i++){
        max = 0;
		for(j=0;j<parties; j++){   /* Scans each party (row) for the highest number */
			if(votes[j][i]>max){
				max = votes[j][i];
				highest = j;
			}
        }
    total[highest]++;
    /* Prints which party won which state */
    printf("State %d was won by Party %c\n", stateNumber++, pLetter[highest]);
	}


    printf("\n");

	printf("Election Results by Party\n----------------------\n");
	printf("Party\t\t# States Won\n\n");
	
	/* cycles through each party letter and the number of states they won*/
    for(i=0;i<parties;i++){
        printf("%c\t\t%d\n", pLetter[i],total[i]);
    }

    int temp = 0;
    int index = 0;

	/*finds the highest number of states won*/
    for(i=0; i<parties; i++){ 
        if(total[i]>temp){
            temp = total[i];
            }
            index = temp;
    }

    printf("\nParty %c has won the election, winning %d states.", pLetter[index-1], index); /*Index element need to be decreased by one to account for the 0th element*/
	}
	fclose(ifp);
	return 0;
}
