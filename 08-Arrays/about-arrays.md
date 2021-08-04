# Array in C/C++.
Is a collection of items *stored at contiguous memory locations* and elements 
can be accessed randomly using **indices** of an array. They are used to store 
similar type of elements as in the data type must be the same for all elements.

> It is not dynamic, and have the address of the first element.

## Why do we need arrays?
We can use normal variables (v1, v2, v3, ..) when we have a small number of 
objects, but if we want *to store a large number of instances*, it becomes 
difficult to manage them with normal variables. **The idea of an array is to 
represent many instances in one variable.**

> Array declaration in C.

```C
int a[3];       // The values will be 'garbage'.
int a[3] = {};  // All the elements will have value 0.
int a[3] = {0}; // All the elements will have value 0.

int a[3] = {1, 2, 3};   // The values will be: 1, 2, 3.
int a[3] = {1};         // The first element have the value 1, the anothers 0.
int a[3] = {[0...1]=3}; // 0 to 1 receives 3, the anothers 0.

int a[] = {4, 5, 6, 7}; // The size will be 4.
```

## Array is a Vector?

**No**, *Vector in C++* is a *class in STL* that represents an array. 
Some advantages of vector over normal arrays are:
1. It's dynamic;
2. It have many in-built functions like: removing an element, etc.

# Strings in C.
Strings are defined as an array of characters. The difference between a 
character array and a string is: the string is terminated with a special 
character ‘\0’ (**NULL**).

> String declaration.
```C
char string[] = "This is a String";
// Use the specifier %s for it.
```
## Properties of Array.
1. It is possible to have array of all types except void and functions.

2. **Array and Pointer are different.**
    They seem similar because array name gives address of first element and array 
    elements are accessed using pointer arithmetic.

3. Arrays are always passed as pointer to functions.

4. A character array initialized with double quoted string has 
last element as ‘\0’ (**NULL**).

5.  Like other variables, arrays can be allocated memory in any of the 
three segments: *data, heap, and stack.* </br>
*Dynamically allocated arrays* are allocated memory on **heap segment**, </br>
*static or global arrays* are allocated memory on **data segment** and </br>
*local arrays* are allocated memory on **stack segment**. </br>

# Observations.
Based on the code below.
```C
#include <stdio.h>

void
fun(int arr[]) {
int i;

/* sizeof should not be used here to get number
	of elements in array*/
int arr_size = sizeof(arr)/sizeof(arr[0]); // incorrect use of sizeof 

for (i = 0; i < arr_size; i++)
	arr[i] = i; // executed only once
}

int
main(void) {
    int i;
    int arr[4] = {0, 0 ,0, 0};
    fun(arr);

    // Use of sizeof is fine here
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    	printf(" %d " ,arr[i]);

    return 0;
}
```
Do not use *sizeof()* for array paramenters.
Because in C, array parameters are treated as pointers. So the expression 
*sizeof(arr)/sizeof(arr[0])* becomes *sizeof(int *)/sizeof(int)* which results 
in 1 for Intel Architecture 32 bit machine *(size of int and int* is 4)* and 
the for loop inside *fun()* is executed only once irrespective of the size of 
the array. So generate other parameter for the function *fun()* to be the size.

## char array.
When declared with double quoted *(" ")*, the compiler puts an one last 
character, **\0**, the string terminator, i.e., is a string.

When declared with single quoted *(' ')*, it is an array of characters in fact.
## Similar properties of Array and Pointer.

1. Array name gives address of first element of array.

2. Array members are accessed using pointer arithmetic.
Compiler uses pointer arithmetic to access array element. E.g., an expression 
like **“arr[i]”** is treated as ***(arr + i)** by the compiler. That is why 
the expressions like ***(arr + i)** work for array arr, and expressions like 
**ptr[i]** also work for pointer ptr.

```C
#include <stdio.h>

int
main(void) {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr = arr;
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("ptr[2] = %d\n", ptr[2]);
    printf("*(ptr + 2) = %d\n", *(ptr + 2));

    return 0;
}
```

3. Array parameters are always passed as pointers, even when we use square brackets.

```C
#include <stdio.h>

void
fun(int ptr[]) {
    int x = 10;

    // size of a pointer is printed. 8
    printf("sizeof(ptr) = %d\n", sizeof(ptr));

    // This allowed because ptr is a pointer, not array.
    ptr = &x;

    printf("*ptr = %d ", *ptr); // 10.
}

int
main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    fun(arr);

    return 0;
}
```

## Some differences of Array and Pointer.

### Difference properly.
Pointers are used for storing address of dynamically allocated arrays and for 
arrays which are passed as arguments to functions. In other contexts, arrays 
and pointer are two different things, see the following programs to justify 
this statement.

> sizeof() operator behavior.

```C
#include <stdio.h>

int
main(void) {
    int array[]  = {10, 20, 30, 40, 50, 60};
    int *pointer = array;

    // sizeof(int) * (number of element in array[]) is printed.
    printf("Size of array[] %ld\n", sizeof(array)); // 4 * 6 = 24.

    // sizeof a pointer is printed which is same for all type
    // of pointers (char*, void*, int*, float*...)
    printf("Size of pointer %ld\n", sizeof(pointer)); // 2 * 4 = 8.

    return 0;
}
```

> Assigning any address to an array variable is not allowed.

```C
#include <stdio.h>

int
main(void) {
    int x = 37;
    int array[] = {10, 20};

    int *pointer = &x;  // This is fine.
    array = &x;         // Compiler Error.

    return 0;
}
```

### Copy of Array and Pointer are different.

1. Pointer: The copy method is **Shallow Copy**, i.e., start pointing to same 
memory location, references to the same values.

2. Array: The copy method is **Deep Copy**, i.e., a copy of the values is did,
in another range of memory.

### Another one.
Consider below two statements in C.
```C
    char s[] = "Code, Drugs, Science and Music by Gaslight.";
    char *s  = "Code, Drugs, Science and Music by Gaslight.";
```

char str[10] = "String";    | char* pointer = "String"; |
----------------------------|---------------------------|
**str** is an Array.        | *pointer* is an pointer variable.
**sizeof(str)** = 10 Bytes. | **sizeof(pointer)** equals to 8 Bytes.
str and &str **are** same.  | pointer and &pointer **aren't** same.
*String* is stored in stack segment | *pointer* is stored at stack segment, "String" is stored at code section of memory.
char str[10] = "String";</br>str = "Hello";  // Invalid* | char* p = "NYC!"; </br> p = "Manhattan"; // Valid.
str++ is valid.             | pointer++ is valid.
char str[10] = "NY-";</br>str[2] = 'C'; // Valid. | char* p = "NYC";</br>p[0] = 'M'; // Invalid*

* (\*) **str** is an address, so we can't assign it.
* (\*) **p[0]** is read only.
* "String literal" is stored in the read-only part of memory by most of the 
compilers. The C and C++ standards say that string literals have **static 
storage** duration, any attempt at modifying them gives undefined behavior.

## Strings

### Read only string in a shared segment.
When a string value is directly assigned to a pointer, in most of the 
compilers, it’s stored in a read-only block (generally in data segment) 
that is shared among functions.

```C
char* str = "Rock and Roll";
```
In the above line "Rock and Roll" *is stored in a shared read-only location*, 
but pointer *str* **is stored in a read-write memory.** You can change str to 
point something else but **cannot** change value at present, "Rock and Roll", 
str. So this kind of string should only be used when we don’t want to modify 
string at a later stage in the program.

### Dynamically allocated in **heap segment**.
Strings are stored like other dynamically allocated *(malloc())* things in C 
and can be shared among functions.

> Exempli Gratia:
```C
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
    char *str;
    int size = 4; // One extra for ‘\0’.
    str = (char*) malloc(sizeof(char) * size);
    *(str+0) = 'N';
    *(str+1) = 'Y';
    *(str+2) = 'C';
    *(str+3) = '\0';

    return 0;
}
```

## A way to have a 2D Array.

```C
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
	int r = 3, c = 4, i, j, count;

	int *arr[r];
	for (i=0; i<r; i++)
		arr[i] = (int *)malloc(c * sizeof(int));

	// Note that arr[i][j] is same as *(*(arr+i)+j)
	count = 0;
	for (i = 0; i < r; i++)
	    for (j = 0; j < c; j++)
	    	arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
	    for (j = 0; j < c; j++)
	    	printf("%d ", arr[i][j]);

	/* Code for further processing and free the 
	dynamically allocated memory */

    return 0;
}
```
