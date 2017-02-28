/*
 * Check: a unit test framework for C
 */

#ifndef ROMAN_H
#define ROMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Roman Roman;

Roman *roman_create(char *Rnum, int Dnum);
char* roman_number(Roman * roman);
int decimal_number(Roman * roman);
void roman_free(Roman * roman);
int roman2dec(char* roman_dec);
char* dec2roman(int value);
int get_unit_roman(int value, int digit_place);
void insert_char(char ch);
char* get_roman();

#define VALID_CHAR 0
#define INVALID_CHAR_ERROR 	1
#define INVALID_SPACE_ERROR 2
#define INVALID_ROMAN_NUMBER_ERROR 3
#define INVALID_OPERATION 4
#define NO_OPERATOR_CHOSEN 5
#define NEGATIVE_DIFFERENCE 6

int error_check(int error)
{
	switch(error)
	{
		case INVALID_CHAR_ERROR :
			printf("Error: Invalid Roman Character : Non-Roman Character identified. Valid Roman Numbers are M, D, C, L, X, V, I.\n");
			printf("Note: All Roman Characters are to be in Capitals Letters. Re-run the program and give a Valid Input.\n");
			exit(0);

		case INVALID_SPACE_ERROR :
			printf("Error: Invalid Space: Tabs and Space Identified. No Tabs and Space allowed in a Roman Number.\n");
			printf("Note: Re-run the program and enter the Roman Number without any spaces and tabs.\n");
			exit(0);

		case INVALID_ROMAN_NUMBER_ERROR :
			printf("Error: Invalid Roman Number: Not a valid Roman Number and does not exist.\n");
			printf("Note: Check the roman number and re-run the program and enter a valid Roman Number.\n");
			exit(0);

		case INVALID_OPERATION :
			printf("Error: Invalid Operation: The given operation is not + or -.\n");
			printf("Note: Re-Run the program and only give + or - as the operator.");
			exit(0);

		case NO_OPERATOR_CHOSEN :
			printf("Error: No Operation: No valid operation given.\n");
			printf("Note: Re-run the program and give + or - as the operator.\n");
			exit(0);

		case NEGATIVE_DIFFERENCE :
			printf("Error: Negative or Zero Difference: The resulting difference is not positive interger.\n");
			printf("Note: For Subtraction, give the First number greater than the Second number. Re-run the program\n");
			exit(0);

		default:
			break;
	}
}

#endif /* ROMAN_H */
