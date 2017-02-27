/*
 * Check: a unit test framework for C
 */

#ifndef ROMAN_H
#define ROMAN_H

typedef struct Roman Roman;

Roman *roman_create(char *Rnum, int Dnum);
char *roman_number(Roman * roman);
int decimal_number(Roman * roman);
void roman_free(Roman * roman);
int roman2dec(char* roman_dec);
char* dec2roman(int value);
int get_unit_roman(int value, int digit_place);
void insert_char(char ch);

#endif /* ROMAN_H */
