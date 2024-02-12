#include "../tests/s21_tests.h"

int main() {
    run_tests();

    return 0;
}

void run_tests(){
    int counter_testcase = 0;

    Suite *list_cases[] = {
        suite_strlen(), NULL
    };

    for (Suite **current_testcase = list_cases; *current_testcase != NULL; current_testcase++)
    {
        run_testcase(*current_testcase, counter_testcase);
        counter_testcase++;
    }

}


void run_testcase(Suite *testcase, int counter_testcase) {
    if(counter_testcase > 1)
    putchar("\n");
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;
    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);

}

