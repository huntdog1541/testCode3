#include <stdio.h>
#include "hello.h"

int main(int args, char ** argv)
{
	printf("Hello World\n");
	int bufSize = 50, strSize = 0;
	int * strSz = &strSize;
	char * str = (char *)malloc(sizeof(char) * bufSize);
	FILE * fin = fopen("test.txt", "r");
	readOut(strSz, str, fin, &bufSize);
	fclose(fin);
	printf("The String is %s\n", str);
	//FILE * fout = fopen("test1.txt", "w");
	//writeOut(strSize, str, fout, bufSize);
	//close(fout);
	return 0;
}

void writeOut(int size, char * str, FILE * fin, int * bufSize)
{
	
}

void readOut(int * size, char * str, FILE * fout, int * bufSize)
{
	char temp = fgetc(fout);
	printf("The char: %c\n", temp);
	while(temp != EOF)
	{
		if(*bufSize >= (*size + 1))
		{
			str = growArray(size, str, bufSize);
		}
		str[(*size)++] = temp;
		printf("Hi\n");
	}
}


//If the array is too small to contain the string
char * growArray(int * size, char * array, int * bufSize)
{
	if(size  >= bufSize)
	{
		bufSize = bufSize + 50;
		char * arry = (char *)malloc(sizeof(char) * (*bufSize));
		int temp = 0;
		while(temp < *size)
		{
			arry[temp] = array[temp];
			temp++;
		}
		while(temp < *bufSize)
		{
			arry[temp] = '\0';
		}
		free(array);
		return arry;
	}
	else
	{
		return array;
	}
	
}
