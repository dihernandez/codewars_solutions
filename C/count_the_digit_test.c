// this code is not mine

#include <stdio.h>
#include <stdlib.h>
#include <criterion/criterion.h>

int nbDig(int n, int d);

void dotest(int n, int d, int exp)
{
    int act = nbDig(n, d);
    if(act != exp)
        printf("Error. Expected %d but got %d\n", exp, act);
    cr_assert_eq(act, exp, "");
}

Test(makeValley, ShouldPassAllTheTestsProvided) {

    dotest(5750, 0, 4700);
    dotest(11011, 2, 9481);
    dotest(12224, 8, 7733);
    dotest(11549, 1, 11905);
}
