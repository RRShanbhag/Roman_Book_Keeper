/*
 * Input and Output characters
 */
#include <stdio.h>
#include "roman.h"

int main(void)
{
    Roman *first_roman;
    Roman *second_roman;
    Roman *answer_roman;

    printf("Enter First Roman Number\n");
    char* temp1 = get_roman();
    first_roman = roman_create(temp1, roman2dec(temp1));

    printf("Enter Second Roman Number\n");
    char* temp2 = get_roman();
    second_roman = roman_create(temp2, roman2dec(temp2));

    int sum = decimal_number(first_roman) + decimal_number(second_roman);

    answer_roman = roman_create(dec2roman(sum), sum);

    printf("Sum = %s\n", roman_number(answer_roman));

    return 0;
}
