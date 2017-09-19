
#include "test_c.h"

int test_cntrl()
{
    int i = 0, j = 0;
    char str1[] = "all a about 	 programming";
    char str2[] = "tutorials    \
            yiibai";

    /* Prints string till control character a */
    while (!iscntrl(str1[i]))
    {
        putchar(str1[i]);
        i++;
    }

    putchar('\n');

    /* Prints string till control character */
    while (!iscntrl(str2[j]))
    {
        putchar(str2[j]);
        j++;
    }

    return(0);
}

int main()
{
    test_cntrl();
    return 0;
}