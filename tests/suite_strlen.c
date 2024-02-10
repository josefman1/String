#include "s21_tests.h"

START_TEST(ooo) {
  char b[] =
      "Ya otigral sotni pjes v tom chisle Venezianskiy Kupez" ck_assert_int_eq(
          s21_strlen(b), strlen(b));
}
END_TEST

START_TEST(aaa) {
  char b[] = "ahahahaa\0adadhkahagddadjlafjla" ck_assert_int_eq(s21_strlen(b),
                                                                strlen(b));
}
END_TEST

START_TEST(aboba) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 6;
  ck_assert_str_eq(s21_strlen(str1, str2, n), strlen(str1, str2, n));
}
END_TEST

START_TEST(amogus) {

  char str[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  Tcase *tc = tcase_create("tc_strlen");

  tcase_add_test(tc, aboba);
  tcase_add_test(tc, amogus);
  tcase_add_test(tc, ooo);
  tcase_add_test(tc, aaa);
  suite_add_tcase(s, tc);

  return s;
}