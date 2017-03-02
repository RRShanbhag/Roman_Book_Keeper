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

    char* temp1 = NULL;

    printf("Enter First Roman Number\n");
    temp1 = get_roman();
	first_roman = roman_create(temp1, roman2dec(temp1));	

    printf("Enter Second Roman Number\n");    
    char* temp2 = get_roman();
    second_roman = roman_create(temp2, roman2dec(temp2));
    
    printf("Enter the operation \n");
	int operator = get_operation();
	
	int sum = 0;

	if (operator == '+')
	{
    	sum = decimal_number(first_roman) + decimal_number(second_roman);
    }

    if (operator == '-')
    {
    	sum = decimal_number(first_roman) - decimal_number(second_roman);
    	if (sum <= 0)
			error_check(NEGATIVE_DIFFERENCE);
    }

    answer_roman = roman_create(dec2roman(sum), sum);

    printf("Answer = %s\n", roman_number(answer_roman));

    return 0;
}
