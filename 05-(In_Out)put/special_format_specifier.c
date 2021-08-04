#include <stdio.h>

int
main(int argc, char const *argv[])
{
    int size;
    printf("Just to get %nthis local.\n", &size);
    printf("The size is %d.\n", size);

    return 0;
}
