# About Preprocessors.
A **Preprocessor** is a system software (a computer program that is designed to 
run on computer’s hardware and application programs). It performs 
preprocessing of the High Level Language(HLL). Preprocessing is the first 
step of the language processing system. Language processing system 
translates the high level language to machine level language or absolute 
machine code(i.e. to the form that can be understood by machine).

## There are 4 main types of preprocessor directives:

    Macros;
    File Inclusion;
    Conditional Compilation;
    Other directives.

# Macros.

Are a piece of code in a program which is given some name. Whenever this 
name is encountered by the compiler the compiler replaces the name with 
the actual piece of code.

**Macros can be called as small functions** *that are not as overhead to 
process.* **If we have to write a function (having a small definition) that 
needs to be called recursively (again and again), then we should prefer a 
macro over a function.**
So, defining these macros is done by preprocessor.

## Types of Macros.
1. **Object-like** *(do not take parameters).* </br>
*exempli gratia:*
```C
#define name value
```
> There is no semi-colon (‘;’) at the end of macro definition.

2. **Function-like** *(Can take parameters).* </br>
*exempli gratia:* </br>
```C
#define name(parameters) (expr)
#define AREA(l, b) (l * b) 
// We can write multi-line macro same like function, 
// but each statement ends with “\”.
#include <stdio.h> 
   
#define MACRO(str) { \
            printf("%s", str); \
        } \
```

3. We can **delete** a Macro definition with **#undef**. </br>
*exempli gratia:*
```C
#undef macro_name
```

# File Inclusion:
This type of preprocessor directive tells the compiler to include a file in 
the source code program.

1. **Header File or Standard files:** These files contains definition of 
pre-defined functions like printf(), scanf() etc. These files must be included
for working with these functions.

```C
#include <file_name>
```
> Where *file_name* is the name of file to be included. The ‘<‘ and ‘>’ 
> brackets tells the compiler to look for the file in standard directory.

2. **User defined files:** When a program becomes very large, it is good 
practice to divide it into smaller files and include whenever needed. 
These types of files are user defined files.

```C
#include "file_name"
```
> " " means to look for the file in the current directory.

# Conditional Compilation:

Is a type of directive which helps to 
compile a specific portion of the program or to skip compilation 
of some specific part of the program based on some conditions.

```C
#ifdef macro_name
    statement1;
    statement2;
    statement3;
    .
    .
    .
    statementN;
#endif
```

# Other directives:
Apart from the above directives there are two more directives 
which are not commonly used.

1. **#undef**: This directive is used to undefine an existing macro.
```C
#undef LIMIT
```
Using this statement will undefine the existing macro LIMIT. 
After this statement every “#ifdef LIMIT” statement will evaluate to false.

2. **#pragma:** This directive have a special purpose and is used 
to turn on or off some features. This type of directives are 
compiler-specific i.e., they vary from compiler to compiler. 
Some of the *#pragma* directives are discussed below:

    2.1 **#pragma startup** and **#pragma exit:** These directives helps us 
    to specify the functions that are needed to run before program startup 
    (before the control passes to *main()*) and just before program exit 
    (just before the control **returns** from *main()*).

    *exempli gratia:*
    ```C
    #include <stdio.h>

    void func1();
    void func2();

    #pragma startup func1
    #pragma exit func2

    void
    func1() {
    	printf("Inside func1()\n");
    }

    void
    func2() {
    	printf("Inside func2()\n");
    }

    int
    main() {
    	printf("Inside main()\n");

    	return 0;
    }
    ```
    2.2 **#pragma warn**: This directive is used to hide the warning message which are displayed during compilation.

    We can **hide the warnings** as shown below:

        2.2.1 **#pragma warn -rvl:** This directive hides those warning 
        which are raised when a function  which is supposed to return a 
        value does not returns a value.

        2.2.2 **#pragma warn -par:** This directive hides those warning which 
        are raised when a function does not uses the parameters passed to it.

        2.2.3 **#pragma warn -rch:** This directive hides those warning which 
        are raised when a code is unreachable. For example: any code written 
        after the return statement in a function is unreachable.

```C
#include <stdio.h>
#define geeks(T) _Generic( (T), char: 1, int: 2, long: 3, default: 0)

int
main(void) {
	// char returns ASCII value which is int type.
	printf("%d\n", geeks('A'));

	// Here A is a string.
	printf("%d",geeks("A"));

	return 0;
}
```
Output:
> 2 </br>
> 0