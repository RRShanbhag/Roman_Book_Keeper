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

START_TEST(test_5Is)
{
	Roman *roman;

	roman = roman_create("IIIII", 5);
    
    ck_assert_int_eq(decimal_number(roman),roman2dec("IIIII"));
    ck_assert_str_eq("IIIII",dec2roman(5));

    roman_free(roman);
}
END_TEST

START_TEST(test_XCX)
{
	Roman *roman;

	roman = roman_create("XCXCXC", 270);
    
    ck_assert_int_eq(decimal_number(roman),roman2dec("XCXCXC"));
    ck_assert_str_eq(roman_number(roman),dec2roman(270));

    roman_free(roman);
}
END_TEST

START_TEST(test_IXC)
{
	Roman *roman;

	roman = roman_create("IXC", 91);
    
    ck_assert_int_eq(decimal_number(roman),roman2dec("IXC"));
    ck_assert_str_eq(roman_number(roman),dec2roman(91));

    roman_free(roman);
}
END_TEST

START_TEST(test_DD)
{
	Roman *roman;

	roman = roman_create("DD", 1000);
    
    ck_assert_int_eq(decimal_number(roman),roman2dec("DD"));
    ck_assert_str_eq(roman_number(roman),dec2roman(1000));

    roman_free(roman);
}
END_TEST

START_TEST(test_VL)
{
	Roman *roman;

    roman = roman_create("VL", 55);
    
    ck_assert_int_eq(decimal_number(roman),roman2dec("VL"));
    ck_assert_str_eq(roman_number(roman),dec2roman(55));

    roman_free(roman);
}
END_TEST

START_TEST(test_A)
{
	Roman *roman;
	
    roman = roman_create("A", 0);
    
    ck_assert_int_eq(decimal_number(roman),roman2dec("A"));
    ck_assert_str_eq(roman_number(roman),dec2roman(0));

    roman_free(roman);
}
END_TEST

Suite * invalid_roman_suite(void)
{
	Suite *s_S;
	TCase *tc_limits;
	s_S = suite_create("Invalid_Roman");

	tc_limits = tcase_create("Limits");

	tcase_add_test(tc_limits, test_5Is);
	tcase_add_test(tc_limits, test_XCX);
	tcase_add_test(tc_limits, test_IXC);
	tcase_add_test(tc_limits, test_DD);
	tcase_add_test(tc_limits, test_VL);
	tcase_add_test(tc_limits, test_A);
	suite_add_tcase(s_S, tc_limits);

	return s_S;
}

int main(void)
{
    int number_failed;
    Suite *s_S;
    SRunner *sr_S;
    
    s_S = invalid_roman_suite();
    sr_S = srunner_create(s_S);
    
    srunner_run_all(sr_S, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr_S);
    srunner_free(sr_S);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}