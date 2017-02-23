#include <stdlib.h>
#include "roman.h"
#include <math.h>
#include <string.h>

/*------------------------- Roman Value Definitions -----------------*/
#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5
#define I 1

/*-------------------------Global Variables--------------------------*/
char roman_numbers[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
int divisors[7] = {M, D, C, L, X, V, I};

typedef int bool;
#define True 1
#define False 0

struct Roman
{
	int Dnum;
	char *Rnum;
};
Roman *roman_create(char *Rnum, int Dnum)
{
	Roman *roman = malloc(sizeof(Roman));

	if (roman == NULL)
	{
		return NULL;
	}

	roman->Dnum = Dnum;
	roman->Rnum = Rnum;

	return roman;
}

int  decimal_number(Roman * roman)
{
	return roman->Dnum;
}

char *roman_number(Roman * roman)
{
	return roman->Rnum;
}

void roman_free(Roman * roman)
{
	free(roman);
	return;
}

/* 
*	This function converts Roman numbers to Decimals. First, it
*	identifies each character in order. Then it assigns value based
*	on the upcoming character. If there are invalid roman number 
*	entry then, it will be checked for error.
*/ 
int roman2dec(char* roman_dec)
{
	int value = 0;
	int index = 0;
	bool units = True;
	int count = 1;

	if(roman_dec[index] == 'I' && roman_dec[index+1] == 'X')
	{
		value += 9;
		index+= 2;
		units = False;
	}

	if(roman_dec[index] == 'I' && roman_dec[index+1] == 'V')
	{
		value += 4;
		index += 2;
		units = False;
	}

	if(roman_dec[index] == 'V')
	{
		value += 5;
		index++;
	} 

	while(roman_dec[index] == 'I' && units == True && count < 4)
	{
		value += 1;
		index++;
		count++;
	}

	units = False;
	return value;
}