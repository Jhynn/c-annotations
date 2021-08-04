#include <stdio.h>
#include <stdbool.h>

/* extern (Global):
 * extern simply tells us that the variable is defined elsewhere
 * and not within the same block where it is used. Basically, the value
 * is assigned to it in a different block and this can be overwritten/changed
 *  in a different block as well.
*/

/* static
 * Static variables have a property of preserving their value even after 
 * they are out of their scope!
*/

int x = 9;

int z;  // Default (for globals) is 0.

int
func(void) {
    return z;  // Variables are scopped statically in C.
}

int
main(int argc, char const *argv[]) {
    const int a = 37;  // 'Never' changes.
    
    // Telling the compiler that the variable z is an extern variable 
    // and has been defined elsewhere (above the main function).
    extern int z;

    // value of extern variable x modified.
    printf("X: %d\n", x);
    x = 2;
    printf("X: %d\n", x);
    // value of extern variable z modified.
    z = 5;

    printf("Z: %d\n", func());
    printf("Z: %d\n", z);
    printf("a: %d\n", a);

    while (x-- > 0) {
        static int y = 5;
        y++;
        printf("The value of y is %d\n", y); 
    }

    bool boolean = false;

    return 0;
}
