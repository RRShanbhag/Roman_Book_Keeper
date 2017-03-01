/*
 * Check: a unit test framework for C
 */

#ifndef ROMAN_H
#define ROMAN_H

/*-------------------------Structure Declaration---------------------*/

typedef struct Roman Roman;

/*-------------------------Function Declarations---------------------*/

Roman *roman_create(char *Rnum, int Dnum);
char* roman_number(Roman * roman);
int decimal_number(Roman * roman);
void roman_free(Roman * roman);
int roman2dec(char* roman_dec);
char* dec2roman(int value);
int get_unit_roman(int value, int digit_place);
void insert_char(char ch);
char* get_roman();
int error_check(int error);
char get_operation();

/*------------- Definition of different type of errors-----------------*/

#define VALID_CHAR 0
#define INVALID_CHAR_ERROR 	1
#define INVALID_SPACE_ERROR 2
#define INVALID_ROMAN_NUMBER_ERROR 3
#define INVALID_OPERATION 4
#define NO_OPERATOR_CHOSEN 5
#define NEGATIVE_DIFFERENCE 6

#endif /* ROMAN_H */
