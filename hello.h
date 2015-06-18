#include <stdio.h>


void writeOut(int size, char * str, FILE * fin, int * bufSize);

void readOut(int * size, char * str, FILE * fout, int * bufSize);

//If the array is too small to contain the string
char * growArray(int * size, char * array, int * bufSize);
