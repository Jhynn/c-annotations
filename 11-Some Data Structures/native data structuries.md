# Enumeration (or enum) in C.
Enumeration (or enum) is a user defined data type in C. It is mainly used 
to assign names - flags - to integral constants, the flags make a program easy 
to read and maintain.
```C
enum days_of_week {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
enum days_of_week day;
day = Wed;  // 3.
```
## Interesting facts about initialization of enum.

1. Two enum flags can have same value. For example, in the 
following C program both ‘Failed’ and ‘Freezed’ have same value 0.

```C
#include <stdio.h>

enum State {
    Working = 1,
    Failed = 0,
    Freezed = 0
};

int
main(void) { 
    printf("%d, %d, %d", Working, Failed, Freezed);

    return 0;
}
```
2. If we do not explicitly assign values to enum flags, the compiler by default
assigns values starting from 0. For example, in the following C program, 
sunday gets value 0, monday gets 1, and so on.

```C
#include <stdio.h>
enum day {
    sunday, monday, tuesday, wednesday,
    thursday, friday, saturday
};

int
main(void) {
	enum day d = thursday;
	printf("The day number stored in d is %d", d);

	return 0;
}
```
3. We can assign values to some flag in any order. 
All unassigned flags get value as value of previous flag plus one.
```C
#include <stdio.h>

enum day {
    sunday = 1, monday, tuesday = 5,
	wednesday, thursday = 10, friday, saturday
};

int
main(void) {
	printf("%d %d %d %d %d %d %d", sunday, monday, tuesday,
			wednesday, thursday, friday, saturday);

	return 0;
}
```
4. The value assigned to enum flags must be some integeral constant, 
i.e., the value must be in range from minimum possible integer value to 
maximum possible integer value.

5. All enum constants must be unique in their scope. 
For example, the following program fails in compilation.
```C
enum state {
    working, failed
};

enum result {
    failed, passed
};

int
main(void) {
    return 0;
} 
```
## Enum vs Macro.
We can also use macros to define constants. 
For example we can define ‘Working’ and ‘Failed’ using following macro.

```C
#define Working 0
#define Failed 1
#define Freezed 2
```
There are some advantages of using enum over macro when many related 
named constants have integral values.

* Enums follow scope rules.
* Enum variables are automatically assigned values. Following is simpler.

```C
enum state {
    Working, Failed, Freezed
};
```

# Structure.

A _struct_ is a composite type and it is defined by the developer.
It define a type that groups primitive types or another structs, 
making possible a type most proper and elegant to solve the problem.
A Structure is a helpful tool to handle a group of logically 
related data items.

## Defining a _struct_.

Keyword **struct**, following of struct's identifier.

```C
struct address { 
    int   zip;
    char* name;   // Members or 
    char* street; // fields of the 
    char* city;   // structure.
    char* state;
}; // Struct is an instruction, then it is needed the ";" at the end.

```
## How to declare structure variables?

A structure variable can either be declared with structure declaration or 
as a separate declaration like basic types.

```C
// A variable declaration with structure declaration.
struct Point {
    int x, y;
} p1; // The variable p1 is declared with 'Point'.

// A variable declaration like basic data types.
struct Point {
    int x, y;
};

int
main(void) {
    struct Point p1; // The variable p1 is declared like a normal variable.
}
```
## A structure may have default values?
No. Because when a definition is done, no memory is allocated,
memory is only allocated when variables are instantiatied.

```C
struct Point {
    int x = 0;  // COMPILER ERROR: cannot initialize members here.
    int y = 0;  // COMPILER ERROR: cannot initialize members here.
};
```
Structure members can be initialized using curly braces ‘{}’. 
For example, following is a valid initialization.

```C
struct Point {
    int x, y;
};

int
main(void) {
    // A valid initialization. Member x gets value 0 and y 
    // gets value 1. The order of declaration is followed.
    struct Point p1 = {0, 1};
}
```
## How to access structure elements?
Structure members are accessed using dot (.) operator.

```C
#include <stdio.h>

struct Point {
    int x, y;
};

int
main(void) {
    struct Point p1 = {0, 1};

    // Accessing members of point p1.
    p1.x = 20;
    printf ("x = %d, y = %d", p1.x, p1.y);

    return 0;
}
```
## What is designated Initialization?
Designated Initialization allows structure members to be initialized in any order.

```C
#include <stdio.h>

struct Point {
    int x, y, z;
};

int
main(void) {
    // Examples of initialization using designated initialization.
    struct Point p1 = {.y = 0, .z = 1, .x = 2};
    struct Point p2 = {.x = 20};
    printf ("x = %d, y = %d, z = %d\n", p1.x, p1.y, p1.z);
    printf ("x = %d", p2.x);
    return 0;
}

```

> Like other primitive data types, we can create an array of structures.

## What is a structure pointer?
Like primitive types, we can have pointer to a structure. 
If we have a pointer to structure, members are accessed using 
arrow (pointer->member) operator or (*(pointer).member).

```C
#include <stdio.h>

struct Point {
    int x, y;
};

int
main(void) {
    struct Point p1 = {1, 2};
    // p2 is a pointer to structure p1.
    struct Point *p2 = &p1;

    // Accessing structure members using structure pointer.
    printf("%d %d", p2->x, (*p2).y);

    return 0;
}
```
## Operations on struct variables in C.
In C, the only operation that can be applied to struct variables is assignment. 
Any other operation (e.g., equality check) is not allowed on struct variables.

## Some limitations of it.

* The C structure does not allow the struct data type to be treated like 
built-in data types:
    We cannot use operators like +, - etc. on Structure variables. 

e.g.:
```C
struct number {
	float x;
};

int
main(void) {
	struct number n1, n2, n3;
	n1.x = 4;
	n2.x = 3;

    n3 = n1 + n2;

	return 0;
}

/* Output: 
 * prog.c: In function 'main':
 * prog.c:10:7: error:
 * invalid operands to binary + (have 'struct number' and 'struct number')
 * n3 = n1 + n2;
*/
```

* No Data Hiding: C Structures do not permit data hiding. 
Structure members can be accessed by any function, 
anywhere in the scope of the Structure.
* Functions inside Structure: C structures do not permit 
functions inside Structure.
* Static Members: C Structures cannot have static members inside their body.
* Access Modifiers: C Programming language do not support access modifiers. 
So they cannot be used in C Structures.
* Construction creation in Structure: Structures in C cannot have constructor 
inside Structures.

## Struct Hack.

What will be the size of following structure?

```C
struct employee {
	int	 emp_id;	// 4 Bytes.
	int	 name_len;	// 4 Bytes.
	char name[0];	// 0 Bytes.
};
```
In gcc, when we create an array of zero length, it is considered as array of 
incomplete type that’s why gcc reports it's size as “0” Bytes. This technique 
is known as “Stuct Hack”. When we create array of zero length inside structure,
it must be (and only) last member of structure.
use it.

“Struct Hack” technique is used to create variable length member in a 
structure. In the above structure, string length of “name” is not fixed, 
so we can use “name” as variable length array.

```C
// This memory allocation
struct employee* e = malloc(sizeof(*e) + sizeof(char) * 128);

// is equivalent to:
struct employee {
	int	 emp_id;
	int	 name_len;
	char name[128];	// character array of size 128 (Bytes).
};
```
> Note: since name is a character array, in malloc instead of 
> “sizeof(char) * 128”, we can use “128” directly, sizeof(128),
> sizeof() is used to avoid confusion.

Now we can use “name” same as pointer. e.g.:
```C
e->emp_id 	= 100;
e->name_len	= strlen("Geeks For Geeks");
strncpy(e->name, "Geeks For Geeks", e->name_len);
```
When we allocate memory as given above, compiler will allocate memory 
to store “emp_id” and “name_len” plus contiguous memory to store “name”. 
When we use this technique, gcc guaranties that, 
“name” will get contiguous memory.

Obviously there are other ways to solve problem, one is we can use 
character pointer. But there is no guarantee that character pointer will get 
contiguous memory, and we can take advantage of this contiguous memory. 
For example, by using this technique, we can allocate and deallocate memory by 
using single malloc and free call (because memory is contagious). 

Other advantage of this is, suppose if we want to write data, we can write 
whole data by using single “write()” call. e.g.
```C
write(fd, e, sizeof(*e) + name_len);	// write emp_id + name_len + name

// If we use character pointer, then we need 2 write calls to write data, e.g.:

write(fd, e, sizeof(*e));				// write emp_id + name_len
write(fd, e->name, e->name_len);		// write name
```
> Note: In C99, there is feature called “flexible array members”, 
> which works same as “Struct Hack”

## Structure Member Alignment, Padding and Data Packing.

What do we mean by data alignment, structure packing and padding?
Predict the output of following program.
```C
#include <stdio.h>

// Alignment requirements (typical 32 bit machine).

// char     	1 byte.
// short int  	2 Bytes.
// int     		4 Bytes.
// double   	8 Bytes.

// structure A.
typedef struct structa_tag {
	char c;
	short int s;
} structa_t;

// structure B.
typedef struct structb_tag {
	int i;
	char c;
	short int s;
} structb_t;

// structure C.
typedef struct structc_tag {
	int s;
	char c;
	double d;
} structc_t;

// structure D.
typedef struct structd_tag {
	int s;
	char c;
	double d;
} structd_t;

int
main(void) {
	printf("sizeof(structa_t) = %ld\n", sizeof(structa_t));
	printf("sizeof(structb_t) = %ld\n", sizeof(structb_t));
	printf("sizeof(structc_t) = %ld\n", sizeof(structc_t));
	printf("sizeof(structd_t) = %ld\n", sizeof(structd_t));

	return 0;
}
```
Every data type in C/C++ will have alignment requirement 
(infact it is mandated by processor architecture, not by language). 
A processor will have processing word length as that of data bus size. 
On a 32 bit machine, the processing word size will be 4 Bytes.

Historically memory is byte addressable and arranged sequentially. 
If the memory is arranged as single bank of one byte width, 
the processor needs to issue 4 memory read cycles to fetch an integer. 
It is more economical to read all 4 Bytes of integer in one memory cycle. 
To take such advantage, the memory will be arranged as group of 4 banks.

The memory addressing still be sequential. If bank 0 occupies an address X, 
bank 1, bank 2 and bank 3 will be at (X + 1), (X + 2) and (X + 3) addresses. 
If an integer of 4 Bytes is allocated on X address (X is multiple of 4), 
the processor needs only one memory cycle to read entire integer.

A variable’s data alignment deals with the way the data stored in these banks. 
For example, the natural alignment of int on 32-bit machine is 4 Bytes. 
When a data type is naturally aligned, the CPU fetches it in minimum 
read cycles.

Similarly, the natural alignment of short int is 2 Bytes. It means, a short int 
can be stored in bank 0 – bank 1 pair or bank 2 – bank 3 pair. 
A double requires 8 Bytes, and occupies two rows in the memory banks. 
Any misalignment of double will force more than two read cycles to 
fetch double data.

> Note that a **double** variable will be allocated on 8 byte boundary on 
> 32 bit machine and requires two memory read cycles. On a 64 bit machine, 
> based on number of banks, double variable will be allocated on 8 byte 
> boundary and requires only one memory read cycle.

## Structure Padding:

In C/C++ a structures are used as data pack. It doesn’t provide any data 
encapsulation or data hiding features (C++ case is an exception due to it's 
semantic similarity with classes).

Because of the alignment requirements of various data types, every member 
of structure should be naturally aligned. The members of structure allocated 
sequentially increasing order. Let us analyze each struct declared 
in the above program.

## Output of Above Program:

For the sake of convenience, assume every structure type variable is allocated 
on 4 byte boundary (say 0x0000), i.e., the base address of structure is 
multiple of 4 (need not necessary always, see explanation of structc_t).

### structure A.

The structa_t first element is char which is one byte aligned, followed by 
short int. short int is 2 byte aligned. If the the short int element is 
immediately allocated after the char element, it will start at an odd 
address boundary. The compiler will insert a padding byte after the char to 
ensure short int will have an address multiple of 2 (i.e., 2 byte aligned). 
The total size of structa_t will be 
sizeof(char) + 1 (padding) + sizeof(short), 1 + 1 + 2 = 4 Bytes.

### structure B.

The first member of structb_t is short int followed by char. 
Since char can be on any byte boundary no padding required in between 
short int and char, on total they occupy 3 Bytes. 
The next member is int. If the int is allocated immediately, 
it will start at an odd byte boundary. 
We need 1 byte padding after the char member to make the address of next 
int member is 4 byte aligned. On total, the structb_t requires 
2 + 1 + 1 (padding) + 4 = 8 Bytes.

### structure C – Every structure will also have alignment requirements.

Applying same analysis, structc_t needs 
sizeof(char) + 7 byte padding + sizeof(double) + sizeof(int) 
= 1 + 7 + 8 + 4 = 20 Bytes. However, the sizeof(structc_t) will be 24 Bytes. 
It is because, along with structure members, structure type variables will 
also have natural alignment. We will understand it by an example. 
Say, we declared an array of structc_t as shown below.

```C
structc_t structc_array[3];
```
Assume, the base address of structc_array is 0x0000 for easy calculations. 
If the structc_t occupies 20 (0x14) Bytes as we calculated, the second 
structc_t array element (indexed at 1) will be at 0x0000 + 0x0014 = 0x0014. 
It is the start address of index 1 element of array. The double member of this 
structc_t will be allocated on 0x0014 + 0x1 + 0x7 = 0x001C (decimal 28) 
which is not multiple of 8 and conflicting with the alignment requirements of 
double. As we mentioned on the top, the alignment requirement of 
double is 8 Bytes.

Inorder to avoid such misalignment, compiler will introduce alignment 
requirement to every structure. It will be as that of the largest member of 
the structure. In our case alignment of structa_t is 2, structb_t is 4 and 
structc_t is 8. If we need nested structures, the size of largest inner 
structure will be the alignment of immediate larger structure.

In structc_t of the above program, there will be padding of 4 Bytes after int 
member to make the structure size multiple of it's alignment. 
Thus the sizeof (structc_t) is 24 Bytes. It guarantees correct alignment even 
in arrays. You can cross check.

### structure D – How to Reduce Padding?

By now, it may be clear that padding is unavoidable. 
There is a way to minimize padding. The developer should declare the 
structure members in their increasing/decreasing order of size. 
An example is structd_t given in our code, 
whose size is 16 Bytes in lieu of 24 Bytes of structc_t.

## What is structure packing?

Some times it is mandatory to avoid padded Bytes among the members 
of structure. For example, reading contents of ELF file header or BMP or JPEG 
file header. We need to define a structure similar to that of the header 
layout and map it. However, care should be exercised in accessing such members. 
Typically reading byte by byte is an option to avoid misaligned exceptions. 
There will be hit on performance.

Most of the compilers provide non standard extensions to switch off the default 
padding like pragmas or command line switches. Consult the documentation of 
respective compiler for more details.

## Pointer Mishaps:

There is possibility of potential error while dealing with pointer arithmetic. 
For example, dereferencing a generic pointer (void*) as shown below can 
cause misaligned exception.
```C
// Deferencing a generic pointer (not safe).
// There is no guarantee that pGeneric is integer aligned.
*(int*) pGeneric;
```
It is possible above type of code in programming. If the pointer _pGeneric_ 
is not aligned as per the requirements of casted data type, there is 
possibility to get misaligned exception.

Infact few processors will not have the last two bits of address decoding, 
and there is no way to access misaligned address. The processor generates 
misaligned exception, if the developer tries to access such address.

## A note on malloc() returned pointer.

The pointer returned by malloc() is _void*_. It can be converted to any 
data type as per the need of developer. The implementer of malloc() should 
return a pointer that is aligned to maximum size of primitive data types 
(those defined by compiler). It is usually aligned to 8 Bytes boundary 
on 32 bit machines.

## Object File Alignment, Section Alignment, Page Alignment.

These are specific to operating system implementer, compiler writers and are 
beyond the scope of this article.

## Difference between C structures and C++ structures.

In C++, struct and class are exactly the same things, except for that 
struct defaults to public visibility and class defaults to private visibility.

Some differences between the C and C++ structures:

* **Member functions inside structure:** Structures in C cannot have member 
functions inside structure but Structures in C++ can have member functions 
along with data members.

* **Direct Initialization:** We cannot directly initialize structure data 
members in C but we can do it in C++.

* **Using struct keyword:** In C, we need to use struct to declare a struct 
variable. In C++, struct is not necessary. For example, let there be a 
structure for Record. In C, we must use “struct Record” for Record variables. 
In C++, we need not use struct and using ‘Record‘ only would work.

* **Static Members:** C structures cannot have static members but is 
allowed in C++.

* **Constructor creation in structure:** Structures in C cannot have 
constructor inside structure but Structures in C++ can have 
Constructor creation.

* **sizeof() operator:** This operator will generate 0 for an empty structure 
in C whereas 1 for an empty structure in C++.

* **Data Hiding:** C structures do not allow concept of Data hiding but is 
permitted in C++ as C++ is an object oriented language whereas C is not.

* **Access Modifiers:** C structures do not have access modifiers as these 
modifiers are not supported by the language. C++ structures can have this 
concept as it is inbuilt in the language.

# Union.

Like _Structures_, _union_ is a user defined data type. In union, all members 
share the same memory location, and is allocated the storage of largest one.

For example in the following C program, both x and y share the same location. 
If we change x, we can see the changes being reflected in y.

A union is a special data type available in C that allows storing different 
data types in the same memory location. You can define a union with 
many members, but only one member can contain a value at any given time. 
Unions provide an efficient way of using the same memory location 
for multiple purposes.

```C
#include <stdio.h>

// Declaration of union is same as structures.
union test {
	int x, y;
};

int
main(void) {
	// A union variable.
	union test \t;

	\t.x = 2;    // \t.y also gets value 2.
	printf("After making x = 2:\n x = %d, y = %d\n\n",
		    \t.x, \t.y);

	\t.y = 10; // \t.x is also updated to 10.
	printf("After making y = 10:\n x = %d, y = %d\n\n",
		    \t.x, \t.y);

	return 0;
}
```

## How is the size of union decided by compiler?

Size of a union is taken according the size of largest member in union.

```C
#include <stdio.h>

union test1 {
	int x;
	int y;
} Test1;

union test2 {
	int x;
	char y;
} Test2;

union test3 {
	int arr[10];
	char y;
} Test3;

int
main(void) {
	printf("test1 = %lu Bytes;\ntest2 = %lu Bytes;\ntest3 = %lu Bytes.\n",
		    sizeof(Test1), sizeof(Test2), sizeof(Test3));

	return 0;
}
```
## Pointers to unions?

Like structures, we can have pointers to unions and can access members using 
the arrow operator (->). The following example demonstrates the same.

```C
#include <stdio.h>

union test {
	int x;
	char y;
};

int
main(void) {
	union test p1;
	p1.x = 65;
	// p2 is a pointer to union p1
	union test* p2 = &p1;

	// Accessing union members using pointer.
	printf("%d %c", p2->x, p2->y);

	return 0;
}
```
## What are applications of union?

Unions can be useful in many situations where we want to use the same memory 
for two or more members. For example, suppose we want to implement a binary 
tree data structure where each leaf node has a double data value, while each 
internal node has pointers to two children, but no data. If we declare this as:

```C
struct NODE {
	struct NODE* left;
	struct NODE* right;
	double data;
};
```
then every node requires 16 Bytes, with half the Bytes wasted for each type 
of node. On the other hand, if we declare a node as following, 
then we can save space.

```C
struct NODE {
	bool is_leaf;
	union {
		struct {
			struct NODE* left;
			struct NODE* right;
		} internal;
		double data;
	} info;
};
```
# Bit Fields in C

In C, we can specify size (in bits) of structure and union members. 
The idea is to use memory efficiently when we know that the value of a field 
or group of fields will never exceed a limit or is withing a small range.

For example, consider the following declaration of date without 
the use of bit fields.

```C
#include <stdio.h>

// A simple representation of the date.
struct date {
	unsigned int d;	// Day;
	unsigned int m;	// Month;
	unsigned int y;	// Year.
};

int
main(void) {
	printf("Size of date is %lu Bytes\n",	// 12 Bytes.
			sizeof(struct date));

	struct date dt = {31, 12, 2014};
	printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);

	return 0;
}
```

The above representation of ‘date’ takes 12 Bytes on a compiler where an 
unsigned int takes 4 Bytes. Since we know that the value of d is always 
from 1 to 31, the value of m is from 1 to 12, we can optimize the space 
using bit fields.

```C
#include <stdio.h>
// Space optimized representation of the date.

struct date {
	// d has value between 1 and 31, so 5 bits are sufficient.
	unsigned int d : 5;

	// m has value between 1 and 12, so 4 bits are sufficient.
	unsigned int m : 4;
	unsigned int y;
};

int
main(void) {
	printf("Size of date is %lu Bytes\n", sizeof(struct date));	// 8 Bytes.

	struct date dt = {31, 12, 2014};

	printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);

	return 0;
}
```
However if the same code is written using signed int and the value of the 
fields goes beyond the bits allocated to the variable and something 
interesting can happen. For example consider the same code but with 
signed integers:

```C
#include <stdio.h>

// Space optimized representation of the date.
struct date {
	int d : 5;	// bits,
	int m : 4;	// bits.
	int y;
};

int
main(void) {
	printf("Size of date is %lu Bytes\n",			// 8 Bytes.
			sizeof(struct date));

	struct date dt = {31, 12, 2014};
	printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);	// -1/-4/2014

	return 0;
}
```
The output comes out to be negative. What happened behind is that the value 
31 was stored in 5 bit signed integer which is equal to 11111. 
The MSB is a 1, so it’s a negative number and you need to calculate the 2’s 
complement of the binary number to get it's actual value which is what is 
done internally. By calculating 2’s complement you will arrive at the value 
00001 which is equivalent to decimal number 1 and since it was a negative 
number you get a -1. A similar thing happens to 12 in which case you get 
4-bit representation as 1100 which on calculating 2’s complement you get 
the value of -4.

## Following are some interesting facts about bit fields in C.

1. A special unnamed bit field of size 0 is used to force alignment on 
next boundary. For example consider the following program.

```C
#include <stdio.h>

// A structure without forced alignment.
struct test1 {
	unsigned int x : 5;
	unsigned int y : 8;
};

// A structure with forced alignment.
struct test2 {
	unsigned int x : 5;
	unsigned int : 0;
	unsigned int y : 8;
};

int
main(void) {
	printf("Size of test1 is %lu Bytes\n",	// 4 Bytes.
			sizeof(struct test1));
	printf("Size of test2 is %lu Bytes\n",	// 8 Bytes.
			sizeof(struct test2));

	return 0;
}
```

2. We cannot have pointers to bit field members as they may not start 
at a byte boundary.

3. It is implementation defined to assign an out-of-range value to a 
bit field member.
```C
#include <stdio.h>

struct test {
	unsigned int x : 2;
	unsigned int y : 2;
	unsigned int z : 2;
};

int
main(void) {
	struct test \t;

	\t.x = 5;
	printf("%d", \t.x);	// Implementation-Dependent

	return 0;
}
```

4. In C++, we can have static members in a structure/class, 
but bit fields cannot be static.
```C
// The below C++ program compiles and runs fine.
struct test1 {
	static unsigned int x : 1;	// static member 'x' cannot be a bit-field
};

int
main(void) {
	return 0;
}
```

5. Array of bit fields is not allowed. 
For example, the below program fails in the compilation.
```C
struct test {
	unsigned int x[10] : 5;
};

int
main(void) {
	// error: bit-field 'x' has invalid type
	return 0; 
}
```

6. Use bit fields in C to figure out a way whether a 
machine is little-endian or big-endian.

# Structure Sorting (By Multiple Rules) in C++.

Name and marks in different subjects (physics, chemistry and maths) 
are given for all students. The task is to compute total marks and ranks of 
all students. And finally display all students sorted by rank.

Rank of student is computed using below rules.

1. If total marks are different, then students with higher marks gets 
better rank.

2. If total marks are same, then students with higher marks in Maths 
gets better rank.

3. If total marks are same and marks in Maths are also same, 
then students with better marks in Physics gets better rank.

4. If all marks (total, Maths, Physics and Chemistry) are same, 
then any student can be assigned bedtter rank.

We use **std::sort()** for Structure Sorting. In Structure sorting, 
all the respective properties possessed by the structure object are sorted on 
the basis of one (or more) property of the object.

In this example, marks of students in different subjects are provided by user. 
These marks in individual subjects are added to calculate the total marks of 
the student, which is then used to sort different students on the basis of 
their ranks (as explained above).

```C++
// C++ program to demonstrate structure sorting.
#include <bits/stdc++.h>

using namespace std;

struct Student {
	string name;	// Given;
	int math;		// Marks in math (Given);
	int phy; 		// Marks in Physics (Given);
	int che; 		// Marks in Chemistry (Given);
	int total;		// Total marks (To be filled);
	int rank;		// Rank of student (To be filled).
};

// Function for comparing two students according
// to given rules.
bool
compareTwoStudents(Student a, Student b) {
	// If total marks are not same then
	// returns true for higher total.
	if (a.total != b.total )
		return a.total > b.total;

	// If marks in Maths are not same then
	// returns true for higher marks.
	if (a.math != b.math)
			return a.math > b.math;

	return (a.phy > b.phy);
}

// Fills total marks and ranks of all Students.
void
computeRanks(Student a[], int n) {
	// To calculate total marks for all Students.
	for (int i=0; i<n; i++)
		a[i].total = a[i].math + a[i].phy + a[i].che;

	// Sort structure array using user defined
	// function compareTwoStudents()
	sort(a, a+5, compareTwoStudents);

	// Assigning ranks after sorting.
	for (int i=0; i<n; i++)
		a[i].rank = i+1;
}

int
main(void) {
	int n = 5;
	Student a[n];

	// Details of Student 1.
	a[0].name = "Bryan" ;
	a[0].math = 80 ;
	a[0].phy = 95 ;
	a[0].che = 85 ;

	// Details of Student 2.
	a[1].name = "Kevin" ;
	a[1].math = 95 ;
	a[1].phy = 85 ;
	a[1].che = 99 ;

	// Details of Student 3.
	a[2].name = "Nick" ;
	a[2].math = 95 ;
	a[2].phy = 85 ;
	a[2].che = 80 ;

	// Details of Student 4.
	a[3].name = "AJ" ;
	a[3].math = 80 ;
	a[3].phy = 70 ;
	a[3].che = 90 ;

	// Details of Student 5.
	a[4].name = "Howie" ;
	a[4].math = 80 ;
	a[4].phy = 80 ;
	a[4].che = 80 ;
	computeRanks(a, n);

	// Column names for displaying data.
	cout << "Rank" <<"\t" << "Name" << "\t";
	cout << "Maths" <<"\t" <<"Physics" <<"\t"
		<< "Chemistry";
	cout << "\t" << "Total\n";

	// Display details of Students.
	for (int i=0; i < n; i++) {
		cout << a[i].rank << "\t";
		cout << a[i].name << "\t";
		cout << a[i].math << "\t"
			<< a[i].phy << "\t"
			<< a[i].che << "\t\t";
		cout << a[i].total << "\t";
		cout << "\n";
	}

	return 0;
}
```

# Flexible Array Members in a structure in C.
Flexible Array Member (FAM) is a feature introduced in the C99 standard of the 
C programming language.

* For the structures in C programming language from C99 standard onwards, 
we can declare an array * without a dimension and whose size is 
flexible in nature.

* Such an array inside the structure should preferably be declared as the last 
member of structure and its size is variable(can be changed be at runtime).

* The structure must contain at least one more named member in addition to the 
flexible array member.

## What must be the size of the structure below?
```C
struct student {
	int stud_id;
	int name_len;
	int struct_size;
	char stud_name[];
};
```
> The size of structure is = 4 + 4 + 4 + **0** = 12
In the above code snippet, the size, i.e., length of array “stud_name” 
isn’t fixed and is an FAM.

The memory allocation using flexible array members (as per C99 standards) 
for the above example can be done as:

```C
struct student* s = malloc(sizeof(*s) + sizeof(char[strlen(stud_name)]));
```
While using flexible array members in structures some convention regarding 
actual size of the member is defined.
In the above example the convention is that the member “stud_name” 
has character size.

For Example, Consider the following structure:
```C
Input: 	id = 15, name = "Kartik" 
Output: Student_id : 15
        Stud_Name..: Kartik
        Name_Length: 6
        Allocated_Struct_size: 18
```

Memory allocation of above structure:

```C
struct student* s = 
        malloc(sizeof(*s) + sizeof(char [strlen("Kartik")]));
```

## Implementation:

```C
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// A structure of type student.
struct student {
	int stud_id;
	int name_len;

	// This is used to store size of flexible
	// character array stud_name[]
	int struct_size;

	// Flexible Array Member(FAM)
	// variable length array must be last
	// member of structure.
	char stud_name[];
};

// Memory allocation and initialisation of structure.
struct student*
createStudent(struct student* s, int id, char a[]) {
	// Allocating memory according to user provided array of characters.
	s = (struct student*) malloc(sizeof(*s) + sizeof(char) * strlen(a));

	s->stud_id = id;
	s->name_len = strlen(a);
	strcpy(s->stud_name, a);

	// Assigning size according to size of stud_name,
	// which is a copy of user provided array a[].
	s->struct_size =
		(sizeof(*s) + sizeof(char) * strlen(s->stud_name));

	return s;
}

void
printStudent(struct student* s) {
	printf("Student_id.: %d\n"
		"Stud_Name..: %s\n"
		"Name_Length: %d\n"
		"Allocated_Struct_size: %d\n\n", 
		s->stud_id, s->stud_name, s->name_len,
		s->struct_size
	);

	// Value of Allocated_Struct_size is in Bytes here.
}

int
main(void) {
	struct student* s1 = createStudent(s1, 523, "Cherry");
	struct student* s2 = createStudent(s2, 535, "Sanjayulsha");

	printStudent(s1);
	printStudent(s2);

	// Size in struct student.
	printf("Size of Struct student: %lu\n",
			sizeof(struct student));

	// Size in struct pointer.
	printf("Size of Struct pointer: %lu",
			sizeof(s1));

	return 0;
}
```

### Important Points:

1. Adjacent memory locations are used to store structure members in memory.
2. In previous standards of the C programming language, we were able to 
declare a zero size array member in place of a flexible array member. 
The GCC compiler with C89 standard considers it as zero size array.

# Anonymous Union and Structure in C.

In C11 standard of C, anonymous Unions and structures were added.

Anonymous unions/structures are also known as unnamed unions/structures as 
they don’t have names. Since there is no names, direct objects (or variables) 
of them are not created and we use them in nested structure or unions.

Definition is just like that of a normal union just without a name or tag.

e.g.:
```C
// Anonymous union example.
union {
   char alpha;
   int num;
};

// Anonymous structure example.
struct {
   char alpha;
   int num;
};
```

Since there is no variable and no name, we can directly access members. 
This accessibility works only inside the scope where the 
anonymous union is defined.

```C
#include <stdio.h>

struct Scope {
	// Anonymous union.
	union {
		char alpha;
		int beta;
	};
	
	struct {
		char gamma;
		int omega;
	}
};

int
main(void) {
	struct Scope x;
	x.beta = 65;
	x.gamma = 'Y';
	x.omega = 37;

	// Note that members of union are accessed directly.
	printf(
		"x.alpha = %c, x.beta = %d"
		"x.omega = %c, x.gamma = %d",
		x.alpha, x.beta, x.omega, x.gamma
	);

	return 0;
}
```
## What about C++?

Anonymous Unions and Structures are NOT part of C++ 11 standard, but most of 
the C++ compilers support them. Since this is a C only feature, the C++ 
implementations don’t allow to anonymous struct/union to have private 
or protected members, static members, and functions.

# Compound Literals in C

Consider below program in C.

```C
#include <stdio.h>

int
main(void) {
	// Compound literal (an array is created without
	// any name and address of first element is assigned
	// to p. This is equivalent to:
	// int arr[] = {2, 4, 6};
	// int* p = arr;
	int* p = (int[]) {2, 4, 6};

	printf("%d %d %d", p[0], p[1], p[2]);

	return 0;
}
```

The above example is an example of compound literals. Compound literals were 
introduced in C99 standard of C. Compound literals feature allows us to create 
unnamed objects with given list of initialized values. In the above example, 
an array is created without any name. Address of first element of array is 
assigned to pointer p.

## What is the use of it?

Compound literals are mainly used with structures and are particularly useful 
when passing structures variables to functions. We can pass a structure object 
without defining it.

e.g.:
```C
#include <stdio.h>

// Structure to represent a coordinate of 2D.
struct Point {
	int x, y;
};

// Utility function to print point.
void
printPoint(struct Point p) {
	printf("%dî + %dĵ", p.x, p.y);
}

int
main(void) {
	// Calling printPoint() without creating any temporary Point variable.

	printPoint((struct Point){2, 3});

	// Without compound literal, above statement would have been written as:
	// struct Point temp = {2, 3};
	// printPoint(temp);

	return 0;
}
```
