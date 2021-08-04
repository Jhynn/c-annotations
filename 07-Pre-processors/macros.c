#include <stdio.h>

// The macros can take function like arguments,
// the arguments are not checked for data type.
#define INCREMENT(x) ++x

// The macro arguments are not evaluated before macro expansion.
// So write like this.
#define multiply(a, b) (a) * (b)  // is different of multiply(a, b) a * b

// The tokens passed to macros can be concatenated
// using operator ## (Token-Pasting operator).
#define merge(a, b) a##b 

// A token passed to macro can be converted to 
// a string literal by using # before it.
#define to_str(s) #s

// macro can be written in multiple lines.
#define print(i, limit) while (i++ < limit) { \
                            printf("Macro! "); \
                            printf("\n"); \
                        }

int
main(void) {
	char *pointer = "Example";
	signed int x  = 10;

	printf("%s\n", INCREMENT(pointer));
	printf("%d\n", INCREMENT(x));

    printf("%d\n", multiply(9, 7+3));

    printf("%d\n", merge(3, 7));

    printf("%s\n", to_str(Example));

    int a = 0;
    print(a, 3);

    #if condition
        /* code */
    #endif

    // Standard macros.
    printf("Current File: %s\n", __FILE__);
    printf("Current Date: %s\n", __DATE__);
    printf("Current Time: %s\n", __TIME__);
    printf("Line Number : %d\n", __LINE__);

    // To remove a macro.
    #undef  multiply // A error will raise if the macro is called below.

	return 0;
}
