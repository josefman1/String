#include "/main.c"

char* strtok(char* str, const char* delim) {
    static char* s = s21_NULL;
    char* tok;
    if(str == s21_NULL) {
        if(s == s21_NULL)
            return s21_NULL;
        } else
    s = str;
    for(size_t i; (*s != '\0'); s++) {
        for(i = 0; (delim[i] != '\0') && (*s != delim[i]); i++);
            if(delim[i] == '\0')
                break;
    }
    if(*s == '\0')
        return s = s21_NULL;
    tok = s++;
    for(size_t i; (*s != '\0'); s++) {
        for(i = 0; (delim[i] != '\0') && (*s != delim[i]); i++);
            if(delim[i] != '\0')
                break;
    }
        if(*s != '\0') {
            *s = '\0';
            s++;
        }
    return tok;
}