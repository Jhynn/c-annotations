// C Programming Language Standard

/*
 * Phases of compilation in C.
 * 1st. Pre-processing: filename.i
 *    Removal of Comments,
 *    Expansion of Macros,
 *    Expansion of the included files,
 *    Conditional compilation.
 * 2nd. Compilation: filename.s
 *      Produce a file with assembly level instructions.
 * 3rd. Assembly: filename.o
 *      This file contain machine level instructions.
 * 4th. Linking: filename.o
 *      Make the references (if dynamic) or put the needed codes.
*/

int
main(int argc, char const *argv[])
{
    int max_integer = 2147483647;
    // 0111_1111_1111_1111_1111_1111_1111_1111.
    return 0;  // Means that the program was successfully runned.
}

// Or...

int
main(void)
{
    /* code */
    return 0;  // Means that the program was successfully runned.
}

// int main() can be called with any number of arguments, only in C,
// but int main(void) can only be called without any argument.
