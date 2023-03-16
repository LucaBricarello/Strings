#pragma once

/** \file stringslib.h
	\brief intestazione delle funzioni di stringslib.c

	Details.
*/

#define HIST_BINS 256 

void Shist(char* instr, int length, int* hist);
void MOSstring(int* hist, char* mos, int* occurrences);
int SOstring(int* hist, char tosearch);
int DOstring(int* hist);
int AOstring(int* hist);







/*
void MOSstring(char* instr, int length, char* mos, int* occurrences);
int SOstring(char* instr, int length, char tosearch);
int DOstring(char* instr, int length);
int AOstring(char* instr, int length);
*/




/*
#ifndef STRINGSLIB.H
#define STRINGSLIB.H

#define HIST_BINS 256

void MOSstring(char* instr, int length, char* mos, int* occurrences);
int SOstring(char* instr, int length, char tosearch);
int DOstring(char* instr, int length);
int AOstring(char* instr, int length);

#endif
*/