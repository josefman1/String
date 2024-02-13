#include "main.c"
#define s21_NULL ((void *)0);
typedef long unsigned s21_size_t;

char *s21_strchr(const char *str, int c);
char *s21_strcpy(char *destination, const char *src);
s21_size_t s21_strlen(const char *str);
char *s21_strstr(const char *destptr, const char *srcptr);
char* strtok(char* str, const char* delim);