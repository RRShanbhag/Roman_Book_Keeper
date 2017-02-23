/*
 *Check: a unit test framework for C
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../src/roman.h"
#include <check.h>

START_TEST(test_roman_create)
{
    Roman *roman;

    roman = roman_create("IIII", NAN);
    
    ck_assert_int_eq(roman2dec(roman_number(roman)),decimal_number(roman));
    ck_assert_str_eq(roman_number(roman), "III");
    
    roman_free(roman);
    
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