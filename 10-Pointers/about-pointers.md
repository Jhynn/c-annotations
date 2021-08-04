# Definition of Pointer:

Pointers store address of variables or a memory location.

```C
type* var_name;
```
To use pointers in C, we must understand below two operators.

* To access address of a variable to a pointer, we use the unary operator 
*& (ampersand)* that returns the address of that variable. 
For example *&x* gives us address of variable *x*.

```C
#include <stdio.h>

int
main(void) {
	int x;

	printf("%p", &x);  // Prints address of x.

	return 0;
}
```

> Unary operator _* (Asterisk)_ which is used for two things:
* To declare a pointer variable: When a pointer variable is declared in C/C++, 
there must a __*__ before it's name.
```C
#include <stdio.h>

int
main(void) {
	int x = 10;

	// 1) Since there is * in declaration, ptr
	// becomes a pointer varaible (a variable
	// that stores address of another variable)
	// 2) Since there is int before *, ptr is
	// pointer to an integer type variable
	int *ptr;

	// & operator before x is used to get address
	// of x. The address of x is assigned to ptr.
	ptr = &x; 

	return 0;
}
```
* To access the value stored in the address we use the unary operator (*) that 
returns the value of the variable located at the address specified by 
it's operand.
```C
#include <stdio.h>

int
main(void) {
	// A normal integer variable
	int Var = 10;

	// A pointer variable that holds address of var.
	int *ptr = &Var;

	// This line prints value at address stored in ptr.
	// Value stored is value of variable "var"
	printf("Value of Var = %d\n", *ptr);

	// The output of this line may be different in different
	// runs even on same machine, this is the address.
	printf("Address of Var = %p\n", ptr);

	// We can also use ptr as lvalue (Left hand
	// side of assignment)
	*ptr = 20; // Value at address is now 20

	// This prints 20
	printf("After doing *ptr = 20, *ptr is %d\n", *ptr);

	return 0;
}
```

## Pointer Expressions and Pointer Arithmetic.
A limited set of arithmetic operations can be performed on pointers. 
A pointer may be:

* incremented ( ++ )
* decremented ( — )
* an integer may be added to a pointer ( + or += )
* an integer may be subtracted from a pointer ( – or -= )

Pointer arithmetic is meaningless unless performed on an array.

## Array Name as Pointers.

An array name acts like a pointer constant. The value of this pointer 
constant is the address of the first element.
For example, if we have an array named val then val and &val[0] can be 
used interchangeably.

```C++
// Program to illustrate Array Name as Pointers in C++.
#include <bits/stdc++.h>

using namespace std;

void
geek(void) {
	int val[3] = {5, 10, 15};
	int* ptr;

	// Assign address of val[0] to ptr.
	// We can use ptr = &val[0]; or ptr = val; (both are same).

	ptr = val;
	cout << "Elements of the array are: ";
	cout << ptr[0] << " " << ptr[1] << " " << ptr[2];
}

int
main(void) {
	geek();

	return 0;
}
```

Now if this ptr is sent to a function as an argument then the array val 
can be accessed in a similar fashion.

## Pointers and Multidimensional Arrays.
Consider pointer notation for the two-dimensional numeric arrays. 
Consider the following declaration.

```C
int nums[2][3] = {{16, 18, 20}, {25, 26, 27}};
// In general, nums[i][j] is equivalent to *(*(nums+i)+j).
```

|   POINTER NOTATION   | ARRAY NOTATION	 | VALUE |
|:--------------------:|:---------------:|:-----:|
| \*(\*nums)	       |    nums[0][0]   |   16  |
| \*(\*nums + 1)	   |    nums[0][1]   |   18  |
| \*(\*nums + 2)	   |    nums[0][2]   |	 20  |
| \*(\*(nums + 1))	   |    nums[1][0]   |	 25  |
| \*(\*(nums + 1) + 1) |    nums[1][1]   |	 26  |
| \*(\*(nums + 1) + 2) |    nums[1][2]   |	 27  |

# Double Pointer (Pointer to Pointer).

We already know that *a pointer points to a location in memory* and thus *used 
to store the address of variables.* So, when we define a *pointer to pointer.* 
The *first pointer* is used to *store the address of the variable*. And the 
*second pointer is used to store the address of the first pointer.* 
That is why they are also known as *double pointers*.

## Declaration of a Double Pointer.

Declaring Pointer to Pointer is similar to declaring pointer in C. 
The difference is we have to place an additional ‘*’.

### Syntax:

```C
int** double_pointer; // Pointer to a pointer of int(enger).
```

e.g.:

```C
#include <stdio.h>

int
main(void) {
	int var = 789;

	int *ptr2;  // Pointer for var.
	int **ptr1; // Double pointer for ptr2.

	ptr2 = &var;  // Storing address of var in ptr2.
	ptr1 = &ptr2; // Storing address of ptr2 in ptr1.

	// Displaying value of var using both, single and double pointers.

	printf("Value of var is %d\n", var);
	printf("Value of var using single pointer: %d\n", *ptr2);
	printf("Value of var using double pointer: %d\n", **ptr1);

	return 0
}
```

# Why C treats Array parameters as Pointers?

```C
void
foo(int arr_param[]) {
	// Just changes the local pointer.
	arr_param = NULL;
}

void
foo(int *arr_param) {
	// idem
	arr_param = NULL;
}
```

It’s preferable to use whichever syntax is more accurate for readability. 
If the pointer points to the base address of a whole array, 
then we should use [].

## Array parameters treated as pointers because of efficiency.

It is inefficient to copy the array data in terms of both memory and time; 
and most of the times, when we pass an array our intention is to just tell 
the array we interested in, not to create a copy of the array.

## Dereference, reference, dereference, reference...

The operator __*__ is used for _dereferencing_ and the operator __&__ is used 
to get the _address_. These operators _cancel effect of each other_ when _used 
one after another_. We can apply them alternatively any of times.

# Dangling, Void, Null and Wild Pointers.

## Dangling pointer.

A pointer pointing to a memory location that has been deleted (or freed) is 
called dangling pointer.

## Void pointer.

_Void_ pointer is a specific pointer type – _void*_ – a pointer that points to 
some data location in storage, which doesn’t have any specific type. 
_Void refers to the type_ (it is not a pointer-to-object). 
Basically the type of data that it points to is can 
be any. If we assign address of _char_ data type to _void_ pointer it will 
become _char_ Pointer, if _int_ data type then _int_ pointer and so on. 
Any pointer type is convertible to a _void_ pointer hence it can point 
to any value.

### Relevant observations:

1. _void_ pointers cannot be dereferenced. It can however be done using 
_typecasting_ the _void_ pointer.

e.g.:
```C
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
	int x = 4;
	float y = 5.5;

	void* ptr;
	ptr = &x;

	// (int*) ptr; - does type casting of void.
	// *((int*) ptr); dereferences the typecasted void pointer variable.

	printf("Integer variable is %d\n", *((int*) ptr));

	ptr = &y;  // To float.
	printf("Float variable is %f\n", *((float*) ptr));

	return 0;
}
```

2. Pointer arithmetic is not possible on pointers of _void_ due to lack of 
concrete value and thus size. However, in _GNU C_ it is allowed by considering 
the size of void is 1.
```C
#include <stdio.h>

int
main(void) {
	int a[2] = {1, 2};
	void* ptr = &a;

	ptr = ptr + sizeof(int);  // 5 Bytes, the next one (int = 4 Bytes).
	printf("%d\n", *(int*) ptr);

	return 0;
}
```

### Advantages.

1. _malloc()_ and _calloc()_ return _void*_ type and this allows these 
functions to be used to allocate memory of any data type 
(just because of void *).
```C
#include <stdlib.h>

int
main(void) {
	// Note that malloc() returns void* which can be
	// typecasted to any type like int*, char*, ...

	int n  = 1;
	int* x = malloc(sizeof(int) * n);
}
```
2. void pointers in C are used to implement generic functions.

## NULL Pointer.

_NULL_ Pointer is a pointer which is pointing to nothing. In case, if we don’t 
have address to be assigned to a pointer, then we can simply use _NULL_.

It is a _macro ((void*) 0)_  and it equals to _int* ptr = 0_;

### Relevant observations:

1. _NULL_ vs Uninitialized pointer: </br>
	* An uninitialized pointer stores an undefined value
	(defined by the environment to not be a 
	valid address for any member or object), i.e., a wild pointer; </br>
	* A null pointer stores a defined value. </br>

2. _NULL_ vs Void Pointer: </br>
	Null pointer is a value, while void pointer is a type.

3. We pass a null pointer to a function argument when we don’t want to pass 
any valid memory address.

e.g.:
```C
#include <stdio.h>

int
main(void) {
	int* ptr = NULL;  // Null Pointer

	printf("The value of ptr is %p", ptr);  // (nil)

	return 0;
}
```

## Wild pointer.

A pointer which has not been initialized to anything (not even NULL), 
will point to some arbitrary memory location. It's known as wild pointer. 
The pointer may be initialized to a non-NULL garbage value that may not 
be a valid address, thus it may cause a program to crash or a 
behave badly.

e.g.:
```C
int
main(void) {
	int x = 10;
	int* p;  		// Wild pointer.

	// int* p = 13; // Some unknown memory location is being corrupted.
					// So, please, never do this.

	p = &x;  		// Now, p is not a wilder pointer...

	return 0;
}
```

If you want pointer to a value (or set of values) without having a variable 
for the value, you should explicitly allocate memory and put the value in 
allocated memory.

```C
#include <stdlib.h>

int
main(void) {
	int* p = (int*) malloc(sizeof(int));

	*p = 12; // This is fine (assuming malloc doesn't return NULL).

	return 0;
}
```

# Pointer to functions.

## Declaration:
```C
int (*coffee)(float intensity, float sugar, float milk);
```
e.g.:
```C
#include <stdio.h>

void
fun(int a) {
	printf("Value of a is %d\n", a);
}

int
main(void) {
	// fun_ptr is a pointer to the function fun().
	void (*fun_ptr)(int) = &fun;

	/* The above line is equivalent of following two lines below.
	 * void (*fun_ptr)(int);
	 * fun_ptr = &fun;
	*/

	// Invoking fun() using fun_ptr.
	(*fun_ptr)(10);

	return 0;
}
```
## Some interesting facts about.

(i). Unlike normal pointers, a function pointer points to code, not data. 
Typically a function pointer stores the start of executable code.

(ii). Unlike normal pointers, we do not allocate de-allocate memory 
using function pointers.

(iii). A function’s name can also be used to get function’s address. 
For example, in the below program, we have removed address 
operator ‘&’ in assignment. We have also changed function call by removing *, 
the program still works. _Someway it remember an array._
```C
#include <stdio.h>

void
fun(int a) {
	printf("Value of a is %d\n", a);
}

int
main(void) {
	void (*fun_ptr)(int) = fun; // & removed
	fun_ptr(10); 				// * removed

	return 0;
}
```
(iv). Like normal pointers, we can have an array of function pointers.

(v). Function pointer can be used in place of switch case. 
For example, in below program, user is asked for a choice between 0 and 2 
to do different tasks.
```C
#include <stdio.h>

void
add(int a, int b) {
	printf("Addition is %d\n", a+b);
}

void
subtract(int a, int b) {
	printf("Subtraction is %d\n", a-b);
}

void
multiply(int a, int b) {
	printf("Multiplication is %d\n", a*b);
}

int
main(void) {
	// fun_ptr_arr is an array of function pointers.
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	
	unsigned int choice, a = 15, b = 10;
	
	printf(
		"Enter Choice:\n"
		"0 for add;\n"
		"1 for subtract;\n"
		"2 for multiply.\n"
	);
	scanf("%d", &choice);

	if (choice < 0 || choice > 2)
		return 0;
	(*fun_ptr_arr[choice])(a, b);  // Or fun_ptr_arr[choice](a, b);

	return 0;
}
```
(vi). Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.

```C
#include <stdio.h>

void
fun1(void) {
	printf("fun1()\n");
}

void
fun2(void) {
	printf("fun2()\n");
}

// A function that receives a simple function
// as parameter and calls the function.

void
wrapper(void (*fun)()) {
	fun();
}

int
main(void) {
	wrapper(fun1);
	wrapper(fun2);

	return 0;
}
```
This point, particularly, is very useful. In C, we can use function 
pointers to avoid code redundancy. For example a simple _qsort()_ function can 
be used to sort arrays in ascending order or descending or by any other order 
in case of array of structures. Not only this, with function pointers and void 
pointers, it is possible to use _qsort()_ for any data type.
```C
#include <stdio.h>
#include <stdlib.h>

// A sample comparator function that is used
// for sorting an integer array in ascending order.
// To sort any array for any other data type and/or
// criteria, all we need to do is write more compare
// functions. And we can use the same qsort().

int
compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int
main(void) {
	int arr[] = {10, 5, 15, 12, 90, 80};
	int n = sizeof(arr)/sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (register int i=0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
```
Similar to qsort(), we can write our own functions that can be used for any 
data type and can do different tasks without code redundancy. Below is an 
example search function that can be used for any data type. In fact we can use 
this search function to find close elements (below a threshold) by writing a 
customized compare function.

```C
#include <stdio.h>
#include <stdbool.h>

bool
compare(const void* a, const void* b) {
	return (*(int*) a == *(int*) b);
}

// General purpose search() function that can be used
// for searching an element *x in an array arr[] of
// arr_size. Note that void pointers are used so that
// the function can be called by passing a pointer of
// any type. ele_size is size of an array element.

int
search(void* arr, int arr_size, int ele_size, void* x,
		bool compare(const void* , const void*)) {

	// Since char takes one byte, we can use char pointer
	// for any type/ To get pointer arithmetic correct,
	// we need to multiply index with size of an array
	// element ele_size.

	char* ptr = (char*) arr;
	int i;
	for (i=0; i < arr_size; i++)
		if (compare(ptr + i*ele_size, x))
			return i;
	// If element not found.
	return -1;
}

int
main(void) {
	int arr[] = {2, 5, 7, 90, 70};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 7;

	printf("Returned index (-1 not found) is %d\n",\
			search(arr, n, sizeof(int), &x, compare));

	return 0;
}
```

(vii). Many object oriented features in C++ are implemented using 
function pointers in C. For example virtual functions. 
Class methods are another example implemented using function pointers. 

# Generic Linked List in C.

Unlike _C++_ and _Java_, _C_ doesn’t support generics. How to create a linked 
list in _C_ that can **be used for any data type?** In _C_, we can use 
**void pointer** and **function pointer** to implement the same functionality. 
The great thing about _void pointer_ is _it can be used to point to any 
data type._ Also, _size of all types of pointers is always the same_, so we 
can always allocate a linked list node. **Function pointer is needed to process 
actual content stored at address pointed by void pointer.**

Below is a snippet _C code_ to demonstrate working of **generic linked list**.

```C
// Generic linked list.
#include <stdio.h>
#include <stdlib.h>
// A linked list node.
struct
Node {
	// Any data type can be stored in this node.
	void* data;
	struct Node* next;
};

/* Function to add a node at the beginning of Linked List.
 * This function expects a pointer to the data to be added
 * and size of the data type.
*/

void
push(struct Node** head_ref, void *new_data, size_t data_size) {
	// Allocate memory for node.
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = malloc(data_size);
	new_node->next = (*head_ref);

	// Copy contents of new_data to newly allocated memory.
	// Assumption: char takes 1 byte.

	int i;
	for (i=0; i < data_size; i++)
		*(char*)(new_node->data + i) = *(char*)(new_data + i);
	// Change head pointer as new node is added at the beginning.
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list. fpitr is used
 * to access the function to be used for printing current node data.
 * Note that different data types need different specifier in printf().
*/

void
printList(struct Node* node, void (*fptr)(void*)) {
	while (node != NULL) {
		(*fptr)(node->data);
		node = node->next;
	}
}
// Function to print an integer.
void
printInt(void *n) {
	printf(" %d", *(int *)n);
}
// Function to print a float.
void
printFloat(void *f) {
	printf(" %f", *(float *)f);
}

int
main(void) {
	struct Node* start = NULL;
	// Create and print an int linked list.

	unsigned int_size = sizeof(int);
	int arr[] = {10, 20, 30, 40, 50}, i;

	for (i=4; i >= 0; i--)
		push(&start, &arr[i], int_size);

	printf("Created integer linked list is \n");
	printList(start, printInt);

	// Create and print a float linked list.
	unsigned float_size = sizeof(float);
	start = NULL;
	float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};

	for (i=4; i>=0; i--)
		push(&start, &arr2[i], float_size);

	printf("\n\nCreated float linked list is \n");
	printList(start, printFloat);
	puts("");

	return 0;
} 
```

# restrict keyword in C.
In the C programming language (after 99 standard), 
a new keyword is introduced known as restrict.

* _restrict_ keyword is mainly used in pointer declarations as a 
type qualifier for pointers.
* It doesn’t add any new functionality. It is only a way for developer 
to inform about an optimizations that compiler can make.
* When we use _restrict_ with a pointer, it tells the compiler that it is the 
only way to access the object pointed by it and compiler doesn’t need to 
add any additional checks.
* If a developer uses _restrict_ keyword and violate the above condition, result 
is undefined behaviour.
* _restrict_ is not supported by _C++_. It is a _C_ only keyword.
```C
#include <stdio.h>

void
use(int* a, int* b, int* restrict c) { 
	*a += *c;

	// Since c is restrict, compiler will
	// not reload value at address c in
	// its assembly code. Therefore generated
	// assembly code is optimized.
	*b += *c;
}

int
main(void) { 
	int a = 50, b = 60, c = 70;
	use(&a, &b, &c);
	printf("%d %d %d", a, b, c);

	return 0;
}
```
# Differencies of const char* p, char* const p and const char* const p.

The qualifier **const** can be applied to the declaration of any variable to 
specify that it's value will not be changed, i.e., it's read-only. 
_const_ keyword applies to whatever is immediately to it's left. 
If there is nothing to it's left, it applies to whatever is 
immediately to it's right.

1. const char* ptr:</br>
	_This is a pointer to a constant character._ You cannot change the value 
	pointed by _ptr_, but you can change the pointer itself.
	“const char*” is a (non-const) pointer to a const char.

```C
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
	char a ='A', b ='B';
	const char *ptr = &a;

	// *ptr = b; illegal statement (assignment of read-only location *ptr).

	printf("Value pointed to by ptr: %c\n", *ptr);
	ptr = &b;  // Can be changed, this is the pointer itself.
	printf("Value pointed to by ptr: %c\n", *ptr);

	return 0;
}
```

> NOTE: There is no difference between _const char* p_ and _char const* p_ 
> as both are pointer to a const char and position of ‘*'(asterik) 
> is also same.

2. char* const ptr:</br>
	This is a constant pointer to non-constant character. 
	You cannot change the pointer p, but can change the value pointed by ptr.
```C
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
	char a ='A', b ='B';
	char *const ptr = &a;

	printf("Value pointed to by ptr: %c\n", *ptr);
	printf("Address ptr is pointing to: %p\n\n", ptr);

	// ptr = &b; illegal statement (assignment of read-only variable ptr)
	// changing the value at the address ptr is pointing to.

	*ptr = b;

	printf("Value pointed to by ptr: %c\n", *ptr);
	printf("Address ptr is pointing to: %p\n", ptr);

	return 0;
}
```
> NOTE: Pointer always points to same address, 
> only the value at the location is changed.

3. const char* const ptr : This is a constant pointer to constant character. You can neither change the value pointed by ptr nor the pointer ptr.
```C
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
	char a ='A', b ='B';
	const char* const ptr = &a;

	printf("Value pointed to by ptr: %c\n", *ptr);
	printf("Address ptr is pointing to: %p\n\n", ptr);

	// ptr = &b; illegal statement (assignment of read-only variable ptr).
	// *ptr = b; illegal statement (assignment of read-only location *ptr).

}
```

> NOTE: _char const* const ptr_ is same as _const char* const ptr_.

# Pointer to an Array.
```C
#include <stdio.h>

int
main(void) {
	int arr[5] = {1, 2, 3, 4, 5};
	int* ptr = arr;

	printf("%p\n", ptr);

	return 0;
}
```

ptr points to the 0th element of the array. 
Similarly, we can also declare a pointer that can point to whole array instead 
of only one element of the array. This pointer is useful when talking about 
multidimensional arrays.

```C
type (*pointer_name)[quantity];
```

Here _*pointer_name_ is a pointer that can point to an array of _quantity_ 
integers. Since subscript have higher precedence than indirection, 
it is necessary to enclose the indirection operator and pointer name inside 
parentheses. 
Here the type of ptr is ‘pointer to an array of quantity integers’.

## Difference.

```C
// C program to understand difference between
// pointer to an integer and pointer to an
// array of integers.
#include <stdio.h>

int
main(void) { 
	int* p;  		// Pointer to an integer.
	int (*ptr)[5];  // Pointer to an array of 5 integers.
	int arr[5]; 

	p = arr;		// Points to 0th element of the arr.
	ptr = &arr; 	// Points to the whole array arr.

	printf("p = %p, ptr = %p\n", p, ptr);
	printf("p = %p, ptr = %p\n", ++p, ++ptr);

	return 0;
}
```
p is pointer to 0th element of the array arr, while ptr is a pointer that 
points to the whole array arr.

* The base type of p is int while base type of ptr is ‘an array of 5 integers’.
* We know that the pointer arithmetic is performed relative to the base size,
  hence the pointer ptr will be shifted forward by 5*4 Bytes.

On dereferencing a pointer expression we get a value pointed to by that 
pointer expression. _Pointer to an array points to an array_, 
so on dereferencing it, we should get the array, and the name of array 
denotes the base address. So whenever a pointer to an array is 
dereferenced, we get the base address of the array to which it points.

# Pointers and two dimensional Arrays:</br>

In a two dimensional array, we can access each element by using 
two subscripts, [], where first subscript represents the row number 
and second subscript represents the column number. The elements of 2-D 
array can be accessed with the help of pointer notation also. 
Suppose arr is a 2-D array, we can access any element, arr[i][j], of the 
array using the pointer expression - \*(\*(arr + i) + j). 
Now we will see how this expression can be derived.

```C
int arr[3][4] = {
	{11, 12, 13, 14},	// 0th 1-D array.
	{15, 16, 17, 18},	// 1st 1-D array.
	{19, 20, 21, 22}	// 2nd 1-D array.
};
```
Since memory in a computer is organized linearly it is not possible 
to store the 2-D array in rows and columns. The concept of rows and 
columns is only theoretical, actually, a 2-D array is stored in a 
row-major order, _i.e._, rows are placed next to each other.

Each row can be considered as a 1-D array, so a two-dimensional array 
can be considered as a collection of one-dimensional arrays that are 
placed one after another. In other words, we can say that 2-D dimensional 
arrays are many 1-D array placed one after another. 
So here _arr_ is an array of 3 elements where each element is a 
1-D array of 4 integers.

We know that the name of an array is a constant pointer that points to 0th 
Since _arr_ is a ‘pointer to an array of 4 integers’, according to pointer 
arithmetic the expression, _arr + 1_, will represent the address, 
base + 16 Bytes, and expression - _arr + 2_ - will represent address 
base + 32 Bytes, _i.e._, arr[].

So we can say that _arr_ points to the 0th 1-D array, 
_arr + 1_ points to the 1st 1-D array and 
_arr + 2_ points to the 2nd 1-D array.

* General case:</br>
	\*(arr + i)  -  arr[i]  -  Base address of _**i**th_ 1-D array 
	-> Points to 0th element of ith 1-D array.
> Note: Both the expressions (arr + i) and *(arr + i) are pointers, 
> but their base type are different. The base type of (arr + i) is 
> ‘an array of 4 units’ while the base type of *(arr + i) or arr[i] is int.

* To access an individual element of our 2-D array, we should be able 
to access any _jth_ element of _ith_ 1-D array.

* Since the base type of *(arr + i) is int and it contains the address of 
0th element of _ith_ 1-D array, we can get the addresses of subsequent 
elements in the _ith_ 1-D array by adding integer values to *(arr + i).

* For example *(arr + i) + 1 will represent the address of 1st element of 
1st element of _ith_ 1-D array and *(arr+i)+2 will represent the address 
of 2nd element of _ith_ 1-D array.

* Similarly *(arr + i) + j will represent the address of _jth_ element of 
_ith_ 1-D array. On dereferencing this expression we can get the _jth_ 
element of the _ith_ 1-D array.

```C
arr					// Points to 0th 1-D array.
*arr				// Points to 0th element of 0th 1-D array.
(arr+i)				// Points to ith 1-D array.
*(arr+i)			// Points to 0th element of ith 1-D array.
(*(arr+i) + j)		// Points to jth element of ith 1-D array.
*(*(arr+i) +j)		// Represents the value of jth element of ith 1-D array.
```
```C
#include <stdio.h>

int
main(void) {
	int arr[3][4] = {
		{10, 11, 12, 13},
		{20, 21, 22, 23},
		{30, 31, 32, 33}
	};

	int i, j;
	for (i = 0; i < 3; i++) {
		printf("Address of array %d: %p\n",
				i, *(arr + i));	// arr[i];

		for (j = 0; j < 4; j++)
			printf("\telement %d at %p\n", 
					arr[i][j], (*(arr + i) + j));	// *(*(arr + i) + j));
	}

	return 0;
}
```
