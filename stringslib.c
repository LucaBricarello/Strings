/** \file stringslib.c
	\brief funzioni per le stringhe

	Details.
*/

#include "stringslib.h"


/*! @brief creates an histogram of the inserted string
	@param instr input string
	@param length string length
	@param location where the histogram needs to be memorized
*/
void Shist(char* instr, int length, int* hist) {

	int i = 0;
	int max = 0;
	int ascii;

	/* Initializes frequency of all symbols to 0 */
	for (i = 0; i < HIST_BINS; i++)
		hist[i] = 0;

	/* Finds frequency of each symbol */
	i = 0;
	while (instr[i] != '\0' && i < length)
	{
		ascii = (int)instr[i];
		hist[ascii] += 1;

		i++;
	}

	return;
}


/*! @brief finds most occurent ASCII symbol in a string
	@param histogram of the given string
	@param moc most occuring character (pointer to)
	@param occurrences frequency of the moc (pointer to)
*/
void MOSstring(int* hist, char* mos, int* occurrences) {

	int i = 0;
	int max = 0;
	int ascii;


	/* Finds maximum frequency */
	max = 0;
	for (i = 0; i < HIST_BINS; i++)
	{
		if (hist[i] > hist[max])
			max = i;
	}

	*mos = (char)max;
	*occurrences = hist[max];

	return;

}

/*! @brief finds in a string the occurrences of a given ASCII symbol
	@param histogram of the given string
	@param tosearch the character
*/
int SOstring(int* hist, char tosearch) {

	return hist[tosearch];		// il parametro tosearch è già il formato ASCII del carattere che si vuole cercare la trasformazione viene fatta dalla funzione getchar() nel main
}

/*! @brief finds in a string the occurrences of digits
	@param histogram of the given string
	@return occurences of digits
*/
int DOstring(int* hist) {

	int i = 48;
	int occurrences = 0;

	//Nella versione precedente, nella condizione del while si aveva: ' hist[i] != '\0' && i < HIST_BINS ' , ma hist (l'istogramma) viene inizializzato a 0 per poi essere aumentato, il problema sta nel fatto che 0 e '\0' (terminatore di stringa) in C sono riconosciuti come uguali
	//In conclusione faccio ciclare su tutti gli elementi dell'istogramma che contengono numeri

	while (i < 58)
	{
		occurrences = occurrences + hist[i];
		i++;
	}

	return occurrences;
}

/*! @brief finds in a string the occurrences of alphabet characters
	@param instr string
	@param length of the string
	@return occurences of alphabet characters
*/
int AOstring(int* hist) {

	int i = 65;
	int occurrences = 0;

	//Nella versione precedente, nella condizione del while si aveva: ' hist[i] != '\0' && i < HIST_BINS ' , ma hist (l'istogramma) viene inizializzato a 0 per poi essere aumentato, il problema sta nel fatto che 0 e '\0' (terminatore di stringa) in C sono riconosciuti come uguali
	//In conclusione faccio ciclare su tutti gli elementi dell'istogramma

	while (i < 91)
	{
		occurrences = occurrences + hist[i];
		i++;
	}

	i = 97;

	while (i < 123)
	{
		occurrences = occurrences + hist[i];
		i++;
	}

	return occurrences;
}