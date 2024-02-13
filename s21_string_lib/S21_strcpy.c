#include "s21_string.h"

char *s21_strcpy(char *destination, const char *src) {
    for (int i = 0; src[i]; i++) {
        destination[i] = src[i];
    }

    destination[s21_strlen(src)] = '\0';

    return destination;
}