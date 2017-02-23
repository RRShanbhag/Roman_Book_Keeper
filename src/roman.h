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

#endif /* ROMAN_H */
