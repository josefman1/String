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



START_TEST(tiktok) {
  char strtok1[] = "me/ma/(mo)/mu";
  char delim1[] = "/()";

  char strtok2[] = "me/ma/(mo)/mu";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(strtok1, delim1);
  char *origin_strtok = strtok(strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST


START_TEST(amo) {

  char str[] = " ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(amo1) {

  char str[] = "\n";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(amo2) {

  char str[] = "\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST


Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  Tcase *tc = tcase_create("tc_strlen");

  tcase_add_test(tc, tiktok);
  tcase_add_test(tc, aboba);
  tcase_add_test(tc, amogus);
  tcase_add_test(tc, ooo);
  tcase_add_test(tc, aaa);
  tcase_add_test(tc, amo);
  tcase_add_test(tc, amo1);
  tcase_add_test(tc, amo2);
  suite_add_tcase(s, tc);

  return s;
}