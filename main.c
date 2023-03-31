/** \file main.c
	\brief reading a string and computing some stats

	Details.
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "stringslib.h"
#include "stringlist.h"
#include "fileIO.h"


#define STR_SIZE 1000


int main() {

	char fname[STR_SIZE];
	strtoken* listPtr;
	strtoken* listPtrC;
	int j = 0;
	int chosenLine;

	char str[STR_SIZE];
	int* hist;
	char mos;
	int occurrences;
	char tosearch;
	int rv;


	printf("Enter file name: ");
	if (fgets(fname, STR_SIZE, stdin) == NULL) {
		printf("ERROR in Main: cannot read input text\n");
		return -1;

	}

	fname[strcspn(fname, "\n")] = 0; // removes EOL from the string

	printf("\nfile name: %s\n", fname);
	
	listPtr = ReadLinesFromFile(fname);
	if (listPtr == NULL)
	{
		printf("ERROR, something went wrong while reading the lines from file and copying them in the list");
		return 0;
	}
	listPtrC = listPtr;

	printf("\nThe file contains the following lines:\n\n");
	while (listPtrC != NULL)
	{
		printf("%d) %s\n", j, listPtrC->token);
		listPtrC = listPtrC->next;
		j++;
	}
	printf("\n");

	listPtrC = listPtr;

	printf("Which line of the file you want to be analized? (the first line is line 0)\nline: ");
	scanf("%d", &chosenLine);
	getchar();	// to ignore EOL when taking the number of the choosen line

	// i make listPtr point to the line that i want to analize
	for (int i = 0; i < chosenLine && listPtr != NULL; i++)
	{
		listPtr = listPtr->next;
	}

	if (listPtr == NULL)
	{
		printf("ERROR: the choosen line does not exist\n");
		return 0;
	}

	strcpy(str, listPtr->token);

	printf("The string is : %s\n", str);

	hist = Shist(str, STR_SIZE);
	if (hist == NULL) {
		printf("ERROR in Main: cannot compute histogram\n");
		return -1;

	}

	rv = MOSstring(hist, &mos, &occurrences);
	if (rv < 0) {
		printf("ERROR in Main: cannot compute most occurring symbol\n");
		return -1;
	}

	printf("The most occurring symbol is '%c' = %d times\n", mos, occurrences);

	occurrences = AOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of alphabet symbols\n");
		return -1;
	}
	printf("The string includes %d alphabet characters\n", occurrences);

	occurrences = DOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of digits\n");
		return -1;
	}
	printf("The string includes %d digits\n", occurrences);


	printf("Enter a symbol: ");
	tosearch = getchar();
	occurrences = SOstring(hist, tosearch);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of the symbol\n");
		return -1;

	}

	printf("Symbol -%c- appears %d times.", tosearch, occurrences);

	if (hist != NULL)
		free(hist);

	ClearList(listPtrC);

	return 0;
}