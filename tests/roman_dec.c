/*
 *Check: a unit test framework for C
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../src/roman.h"
#include <check.h>
#include <string.h>

char* get_romans();

START_TEST(test_roman_create)
{

	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 1;

    fp = fopen("../Roman_Numbers.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    Roman *roman;
    int i = 1;
    
    while (i <= 2000)
    {
    line = get_romans(fp);
    roman = roman_create(line, i);
    
    ck_assert_str_eq(roman_number(roman), line);
   	ck_assert_int_eq(roman2dec(roman_number(roman)),decimal_number(roman));
    
   	roman_free(roman);	
   	i++;
    } 
    fclose(fp);
    if (line)
        free(line);  
}
END_TEST

Suite * roman_suite(void)
{
	Suite *s;
	TCase *tc_core;
	s = suite_create("Roman");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_roman_create);
	suite_add_tcase(s, tc_core);

	return s;
}

char* get_romans(FILE * fp)
{
	char * line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, fp);
    if(read != -1)
    {
       	line[strlen(line)-1] = '\0';
        return line;
    }
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;
    
    s = roman_suite();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}