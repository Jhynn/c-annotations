#include <stdio.h>

int
main(int argc, char const *argv[]) {
    
    int just_the_number;
    printf("Enter something, and finish with a number: ");
    // Blahblahblah 37
    scanf("%*s %d", &just_the_number);

    printf("The number is %d.\n", just_the_number);

    FILE* ptr = fopen("abc.txt","r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }

    char buf[4];
    while (fscanf(ptr, "%*s %*s %s ", buf) == 1)
        printf("%s\n", buf);

    char s[64];
    printf("Enter a string: ");
    fgets(s, 64, stdin);
    printf("Your data: %s\n", s);

    int width = 9;
    printf("%*d\n", width, 9);

   return 0;
}
