CC = gcc -Wall -Werror -Wextra
C11 = -std=c11
CPP = cppcheck --enable=all --supress=missingIncludeSystem

MAIN = main.c

CHECK_LIBS = -lcheck -lsubunit -lm 

OBJ_TESTS = $(CFILES_TESTS:.c=.o)

CFILES_TESTS = $(wildcard tests/*.c)
OBJ_TESTS_DONE = $(addprefix build/,$(CFILES_TESTS:.c=.o))
MY_LIB = $(build/s21_string.a)
CFILES_STR_LIB = $(wildcard s21_string_lib/*.c)
OBJ_STR_LIB = $(CFILES_STR_LIB:.c=.o)
OBJ_STR_LIB_DONE = $(addprefix build/,$CFILES_STR_LIB:.c=.o)

all: s21_string

s21_string: lib tests main final 

lib: $(OBJ_STR_LIB)
	ar rcs $(MY_LIB) $(OBJ_STR_LIB_DONE)

tests: $(OBJ_TESTS)

main: $(CC) -c $(MAIN) -o build/main.c

final: $(CC) $(C11) build/main.o $(OBJ_TESTS_DONE) -o s21_string -L. $(MY_LIB) $(CHECK_LIBS)

cppcheck: $(CPP) $(CFILES_STR_LIB)

clang-format: $(find -name "*.c" -o -name "*.h" | xargs clang-format -n)

clean: rm -f s21_string $(OBJ_STR_LIB_DONE) $(OBJ_TESTS_DONE) build/main.o $(MY_LIB)

rebuild: clean s21_string

$(OBJ_STR_LIB): %.o %.c
	$(CC) $(C11) -c $< -o build/$@

$(OBJ_TESTS): %.o %.c
	$(CC) $(C11) -c $< -o build/$@

	