#include <stdlib.h>
#include "roman.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

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
char *roman_result = NULL;
char* temp=NULL;
size_t roman_result_size = 0, roman_result_index = 0;

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

char* roman_number(Roman * roman)
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
	bool units = True, tens = True, hundereds = True, thousands = True;

	//THOUSANDS PLACE
	if (roman_dec[index] == 'M' && thousands == True)
	{
		int count = 0;
		while(roman_dec[index] == 'M' && count < 10)
		{
			value+=1000;
			index++;
			count++;
		}
	
	thousands=False;			//printf("line45: %d\n", value);
	}

	//HUNDEREDS PLACE
	if (roman_dec[index] == 'C' || roman_dec[index] == 'D' && hundereds == True)
	{
		thousands = False;
		int count = 1;

		if(roman_dec[index] == 'C' && roman_dec[index+1] == 'M')
		{
			value += 900;
			index += 2;
			hundereds = False;
		}
		if(roman_dec[index] == 'C' && roman_dec[index+1] == 'D')
		{
			value += 400;
			index += 2;
			hundereds=False;
		}
		if(roman_dec[index] == 'D')
		{
			value += 500;
			index++;
		}
		while(roman_dec[index] == 'C' && hundereds == True && count < 4)
		{
			value += 100;
			index++;
		}
	hundereds = False;
	}

	
	//TENS PLACE
	if (roman_dec[index] == 'X' || roman_dec[index] == 'L' && tens == True)
	{
		hundereds = False; thousands = False;
		int count = 1;

		if(roman_dec[index] == 'X' && roman_dec[index+1] == 'C')
		{
			value += 90;
			index+= 2;
			tens = False;
		}

		if(roman_dec[index] == 'X' && roman_dec[index+1] == 'L')
		{
			value += 40;
			index += 2;
			tens = False;
		}

		if(roman_dec[index] == 'L')
		{
			value += 50;
			index++;
		} 

		while(roman_dec[index] == 'X' && tens == True && count < 4)
		{
			value += 10;
			index++;
			count++;
		}

		tens = False;
	}


	//UNITS PLACE
	if (roman_dec[index] == 'I' || roman_dec[index] == 'V' && units == True)
	{
		hundereds = False; thousands = False; tens = False;
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
	}
	return value;
}

/*
*	This converts Decimal to Roman number.Get each Decimal place value
*	and assign Roman number to the decimal value using get_unit_roman 
*	function. If the value is greater or equal to 5000, the value of 
*	Roman Number is not defined in this problem and thus reports error.
*/

char* dec2roman(int value)
{
	int remainder = value;
	int quotient1 = 0;
	int quotient2 = 0;
	int digit_place = 0;
	
	roman_result=NULL;
	roman_result_size = 0; 
	roman_result_index = 0;
	
	while(remainder != 0)
	{
		remainder = get_unit_roman(value, digit_place);
		digit_place++;
		if (remainder == 0)
			break;
		value = remainder;	
	}

	insert_char('\0');
	return roman_result;
}

/*
*	Get each value by first dividing in the order of the highest roman
*	number i.e. M. Since M is just repeatition of the thousand place 
*	value, it is just repeated equal to resulting quotient. Next divisor
*	is D i.e. 500. If the quotient is 0 and the remainder is 0, the value 
*	assigned would be D. If the quotient is 0 and the remainder is not 0 
*	then divide by 100. If the new quotient is 4 then Roman value for 
*	hundered's place is CD. If the new quotient is less than 4 then the 
*	Roman number value is C repeatitions of the new quotient. However,
*	quotient when divided by D is 1 and the new quotient divided by C 
* 	is 4 then Roman number at Hundered's place is CM otherwise D followed 
*	by number of C repeatitions of the new quotient. Similar steps is 
*	followed for Ten's and Unit's place as well.
*/

int get_unit_roman(int value, int digit_place)
{
	int remainder = 0;
	int quotient1 = 0, quotient2 = 0;
	char ch;
	
	remainder = value % divisors[digit_place];
	quotient1 = value / divisors[digit_place];

	if (roman_numbers[digit_place] == 'C' || roman_numbers[digit_place] == 'X' || roman_numbers[digit_place] == 'I')
		return remainder;
	
	if (digit_place == 0)
	{
		for(int i = 0; i < quotient1; i++)
		{
			ch = roman_numbers[digit_place];
			insert_char(ch);
		}
		return remainder; 
	}
	if (remainder == 0)
	{
		ch = roman_numbers[digit_place];
		insert_char(ch);
		return remainder;
	}

	value = remainder;
	remainder = value % divisors[digit_place+1];
	quotient2 = value / divisors[digit_place+1];

	if (quotient1 == 0)
	{
		if (quotient2 == 4)
			{
				ch = roman_numbers[digit_place+1];
				insert_char(ch);
				ch = roman_numbers[digit_place];
				insert_char(ch);
			}

		if (quotient2 != 0 && quotient2 != 4)
		{
			for (int i = 0; i < quotient2; i++)
			{
				ch = roman_numbers[digit_place+1];
				insert_char(ch);
			}
		}
		return remainder;
	}

	if (quotient1 == 1)
	{
		if (quotient2 == 4)
		{
			ch = roman_numbers[digit_place+1];
			insert_char(ch);
			ch = roman_numbers[digit_place-1];
			insert_char(ch);
		}
		if (quotient2 == 0)
		{
			ch = roman_numbers[digit_place];
			insert_char(ch);
		}
		
		if (quotient2 != 0 && quotient2 != 4)
		{
			ch = roman_numbers[digit_place];
			insert_char(ch);
			for(int i = 0; i < quotient2; i++)
			{
				ch = roman_numbers[digit_place+1];
				insert_char(ch);
			}
		}
	}
	return remainder;
}

/*
*	This function is for inserting characters dynamically for values
*	obtained in get_unit_roman function. 
*/
void insert_char(char ch)
{
	if (roman_result_size <= roman_result_index)
	{
		roman_result_size += 1;
		temp = realloc(roman_result, roman_result_size);
		if(!temp)
		{
			free(roman_result);
			roman_result = NULL;
			//break;
		}
		roman_result = temp;
	}
	roman_result[roman_result_index++] = ch;
	return;	
}

char* get_roman()
{
	char *line = NULL, *tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;
    int error;

	while(ch)
	{
		error = 10;
		ch = getc(stdin);

		if (ch == ' ' || ch == '\t')
    	{
    		error = INVALID_SPACE_ERROR;
    		break;
    	}

    	for(int i = 0; i < 7; i++)
    	{
    		if(ch == roman_numbers[i] || ch == '\n')
    			error = VALID_CHAR;
    	}

    	if (error != 0)
    	{
    		error = INVALID_CHAR_ERROR;
    		break;
    	}

		if (ch == EOF || ch == '\n')
            ch = 0;

        if (size <= index) 
        {
            size += 1;
            tmp = realloc(line, size);
            if (!tmp) 
            {
                free(line);
                line = NULL;
                break;
            }

            line = tmp;
        }

        line[index++] = ch;
	}
	error_check(error);
	return line;
}