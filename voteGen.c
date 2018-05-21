#include <stdio.h>
#define ROWS 12
#define COLS 8
int main(){
	
	FILE *ifp;
	int votes[ROWS][COLS], i,j;
	
	ifp = fopen("scores.txt", "w");
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			votes[i][j] = rand()%101;
			fprintf(ifp, "%d\n", votes[i][j]);
		}
	}
	fclose(ifp);
	return 0;
	
}
