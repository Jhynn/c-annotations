# Definition.

A function is a set of statements that take inputs, do some specific 
computation and produces a value.

The idea is to put some commonly or repeatedly done task together and make a 
function, so that instead of writing the same code again and again, for 
different inputs, we can call the function.

## Function Declaration.

A function declaration tells the compiler about the *number of parameters* 
function takes, *data-types of parameters and return type of function*. Putting
*parameter names in function declaration is optional*, but it *is necessary to 
put them in the definition*.

### Function prototype.

```C
[qualifier] <return_type>
func_name([<type>, <type arg_name>]) {
    // statements...
    return <value>;
}
```
## Why do we need **functions**?

* **It help us in reducing code redundancy.** If functionality is performed 
at multiple places in software, then rather than writing the same code, again 
and again, we create a function and call it everywhere. This also helps in 
maintenance as we have to change at one place if we make future changes to the 
functionality.

* **It make code modular.** Consider a big file having many lines of codes. 
It becomes really simple to read and use the code if the code is divided 
into functions.

* **It provide abstraction.** For example, we can use library functions 
without worrying about their internal working.

## Parameter Passing to functions.

* The *parameters passed to function* are called **actual parameters**
*(or arguments)*.

* The *parameters defined on the function* are called **formal parameters**.

### There are two most popular ways to pass parameters.

* **Pass by Value:** In this parameter passing method, values of actual 
parameters are copied to function’s formal parameters and the two types 
of parameters are stored in different memory locations. So any changes 
made inside functions are not reflected in actual parameters of caller.

* **Pass by Reference:** Both actual and formal parameters refer to same 
locations, so any changes made inside the function are actually reflected 
in actual parameters of caller.

> In C, parameters are always passed by value.
> To get the address, i.e., pass by reference, use the operaor: **&**

## Following are some important points about functions in C.

1. Every C program has a function called main() that is called by operating 
system when a user runs the program.

2. Every function has a return type. If a function doesn’t return any value, 
then void is used as return type. Moreover, if the return type of the function 
is void, we still can use return statement in the body of function definition 
by not specifying any constant, variable, etc. with it, by only mentioning the 
**‘return;’** statement which would symbolise the termination of the function.

3. In C, functions can return any type except arrays and functions. We can get 
around this limitation by returning pointer to array or pointer to function.

4. Empty parameter list in C mean that the parameter list is not specified and 
function can be called with any parameters. In C, it is not a good idea to 
declare a function like *func()*. To declare a function that can only be called 
without any parameter, we should use **void**, *id est*, **func(void)**.

5. If in a C program, a function is called before it's declaration then the C 
compiler automatically assumes the declaration of that function is the 
following way: *int function name();* </br>
And in that case if the return type of that function is different than int, 
compiler would show an error.

## Functions that are executed before and after *main()* in C.
With GCC family of C compilers, we can mark some functions to execute before 
and after main(). So some startup code can be executed before main() starts, 
and some cleanup code can be executed after main() ends.

> exempli gratia:

```C
#include <stdio.h>

/* 
 * Apply the constructor attribute to myStartupFun() so that it 
 * is executed before main()
*/
void myStartupFun(void) __attribute__ ((constructor));


/* 
 * Apply the destructor attribute to myCleanupFun() so that it 
 * is executed after main()
*/
void myCleanupFun(void) __attribute__ ((destructor));


// Implementation of myStartupFun
void
myStartupFun(void) {
	printf("Startup code before main().\n");
}

// Implementation of myCleanupFun
void
myCleanupFun(void) {
	printf("Cleanup code after main().\n");
}

int
main(void) {
	printf("Hello!\n");

	return 0;
}
```
## *return* statement **vs** *exit()* function in *main()*
When *exit(0)* is used to exit from program, destructors for locally 
scoped non-static objects are not called. But destructors are called 
if *return 0;* is used.

## Methods to **return multiple values** from a function in C:

1. By using **Pointers**;
2. By using **Structures**;
3. By using **Arrays**.

### e.g.: A function that informs the greater and smaller number given.

* Case 1 - Using **Pointers**:
changes their value using pointer.
```C
#include <stdio.h>

void
compare(int a, int b, int* add_great, int* add_small) {
	if (a > b) {
		// a is stored in the address pointed
		// by the pointer variable *add_great.
		*add_great = a;
		*add_small = b;
	} else {
		*add_great = b;
		*add_small = a;
	}
}

int
main(void) {
	int great, small, x, y;

	printf("Please, enter two numbers.\n");
	printf("1st: ");
	scanf("%d", &x);
	printf("2nd: ");
	scanf("%d", &y);

	// The last two arguments are passed
	// by giving addresses of memory locations.
	compare(x, y, &great, &small);

	printf("The greater number is %d and the "
			"smaller number is %d\n", great, small);

	return 0;
} 
```

* Case 2 - Using **Structures**: Define a structure with two integer variables 
and store the greater and smaller values into those variable.
```C
#include <stdio.h>

struct
greaterSmaller { 
	int greater, smaller;
};

typedef struct greaterSmaller Struct;

Struct
findGreaterSmaller(int a, int b) {
	Struct s;
	if (a > b) {
		s.greater = a;
		s.smaller = b;
	} else {
		s.greater = b;
		s.smaller = a;
	}

	return s;
}

int
main(void) {
	int x, y;
	Struct result;

	printf("Please, enter two numbers.\n");
	printf("1st: ");
	scanf("%d", &x);
	printf("2nd: ");
	scanf("%d", &y);


	result = findGreaterSmaller(x, y);
	printf("The greater number is %d and the "
		"smaller number is %d", result.greater, result.smaller);

	return 0;
}
```

* Case 3 - Using **Array**: when an array is passed as an argument, then it's 
base address is passed to the function, i.e., this is a passing by reference.
Assuming the highest value in arr[0] and lowest in arr[1].
```C
#include <stdio.h>

void
findGreaterSmaller(int a, int b, int arr[]) {
	if (a > b) {
		arr[0] = a;
		arr[1] = b;
	} else {
		arr[0] = b;
		arr[1] = a;
	}
}

int
main() {
	int x, y;
	int arr[2];

	printf("Please, enter two numbers.\n");
	printf("1st: ");
	scanf("%d", &x);
	printf("2nd: ");
	scanf("%d", &y);

	findGreaterSmaller(x, y, arr);

	printf("The greater number is %d and the "
		"smaller number is %d", arr[0], arr[1]);

	return 0;
}
```
## An observation.

In C, functions are global by default. The “static” keyword before a function 
name makes it static. For example, below function *fun()* is **static**.

Unlike global functions in C, access to static functions is restricted to the 
file where they are declared. Therefore, when we want to restrict access to 
functions, we make them static. Another reason for making functions static can 
be reuse of the same function name in other files.

## Some ways to exit of *main()*.

1. With *exit()* function: it terminates the process normally. </br>
	1.1 Syntax:
	```C
	void exit(int status);
	```
	1.2 status:
	Status value returned to the parent process. Generally, a status value of 
	*0* or *EXIT_SUCCESS* indicates *success*, and *any other value in the 
	range 1 to 255* or the constant *EXIT_FAILURE* is used to indicate an 
	*error*.

	1.3 **exit()** performs following operations: </br>
		* Flushes unwritten buffered data. </br>
		* Closes all open files. </br>
		* Removes temporary files. </br>
		* Returns an integer exit status to the operating system.

2. *abort(void)* function.
	```C
	void abort(void);
	```
	It may not close files that are open. It may also not delete temporary 
	files and may not flush stream buffer.

	* This function actually terminates the process by raising a 
	*SIGABRT signal (Abnormal termination of the process)*, and your 
	program can include a handler to intercept this signal.

3. *assert()* function.
	```C
	void assert(int expression);
	```
	If expression evaluates to *0 (false)*, then the expression, 
	sourcecode filename, and line number are sent to the standard error, 
	and then *abort()* function is called. If the identifier 
	*NDEBUG (“no debug”)* is defined with *#define NDEBUG* then the 
	macro assert does nothing.

	```C
	#include <assert.h>

	void
	open_record(char* record_name) {
		assert(record_name != NULL);
		// Rest of code
	}

	int
	main(void) {
		open_record(NULL);
	
	}
	```
	> Assertion failed: expression, file filename, line line-number.

4. The *_Exit()* function in C/C++ gives normal termination of a program 
without performing any cleanup tasks. For example it does not execute 
functions registered with *atexit()*.

	e.g.:
	```C
	#include <stdio.h>
	#include <stdlib.h>

	int
	main(void) {
		int exit_code = 10;
		printf("Termination using _Exit().\n");
		_Exit(exit_code); // No output.
	}
	```
	Another:
	```C
	#include<bits/stdc++.h>

	using namespace std;

	void
	fun(void) {
		cout << "Exiting";
	}

	int
	main() {
		atexit(fun);
		_Exit(10);
	}
	```
