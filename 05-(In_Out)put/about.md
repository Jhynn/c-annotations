# Input & Output in C/C++

## Input: _scanf()_
It returns total number of Inputs (spacebar delimited) 
**Scanned successfully**, or EOF if input failure occurs before the first 
receiving argument was assigned.

## Output: _printf()_

It returns total number of **Characters Printed**, Or negative value if an 
output error or an encoding error.

### e.g. (EXEMPLI GRATIA):

```C
#include <stdio.h>

int main()
{
    char st[] = "CODING";

    printf("While printing ");
    printf(", the value returned by printf() is %d.", printf("%s", st);

    return 0;
}
```
> Output: While printing CODING, the value returned by printf() is 6.

## Return type of _getchar()_, _fgetc()_ and _getc()_
Is **_int_**, not _char_.

## Scansets in C
1. _scanf()_ family functions support scanset specifiers which are represented 
by **%[]. Inside scanset, we can specify single character or range of characters.** 
While processing scanset, scanf will process only those characters which 
are part of scanset. We can define scanset by putting characters inside 
squre brackets. Please note that the scansets are case-sensitive.

e.g.:
```C
#include <stdio.h>

int main(void)
{
	char str[128];

	printf("Enter a string: ");
	scanf("%[A-Z]s", str);

	printf("You entered: %s\n", str);

	return 0;
}
```
2. If first character of scanset is ‘^’, then the specifier will stop reading 
after first occurrence of that character.

```C
#include <stdio.h>

int main(void)
{
	char str[128];

	printf("Enter a string: ");
    // C is a medium level language, ok?
	scanf("%[^o]s", str);

	printf("You entered: %s\n", str);
    // C is a medium level language, o

	return 0;
}
```

## _puts()_ and _printf()_

_puts()_ can be preferred for printing a string because it is generally 
less expensive (implementation of _puts()_ is generally simpler than 
_printf()_), and if the string has formatting characters like ‘%’, then 
_printf()_ would give unexpected results. Also, if str is a user input 
string, then use of _printf()_ might cause security issues (see this for details).
Also note that _puts()_ moves the cursor to next line. If you do not want the 
cursor to be moved to next line, then you can use following variation of _puts()_.

```C
fputs(str, stdout);
```
e.g.:
```C
#include <stdio.h>

int main()
{
	printf("100% in C.");
	return 0;
}
```
> Output: warning: format '%s' expects a matching 'char *' argument [-Wformat=]
```C
#include <stdio.h>

int main()
{
	puts("100% in C.");
	return 0;
}
```
> Output: 100% in C.

## _prints()_

### _printf(const char* str, ...)_
Is used to print character stream of data on **stdout** console.

### _sprintf(char* str, const char *string,...)_
String print function instead of printing on console, store it on char buffer 
which are specified in sprintf.

#### e.g.:
```C
#include <stdio.h>
int main()
{
	char buffer[50];
	int a = 10, b = 20, c;
	c = a + b;
	sprintf(buffer, "Sum of %d and %d is %d", a, b, c);

	// The string "sum of 10 and 20 is 30" is stored
	// into buffer instead of printing on stdout.
	printf("%s", buffer);

	return 0;
}
```

### _fprintf(FILE *fptr, const char *str, ..._
It is used to print the string content in file, not on stdout console.

#### e.g.:
```C
#include <stdio.h>

int main()
{
	int i, n = 2;
	char str[50];

	// Open file sample.txt in write mode.
	FILE* fptr = fopen("sample.txt", "w");
	if (fptr == NULL) {
		printf("Could not open file.");
		return 0;
	}

	for (i = 0; i < n; i++) {
		puts("Enter a name: ");
		gets(str);
		fprintf(fptr,"%d. %s\n", i, str);
	}

	fclose(fptr);

	return 0;
}
```

## _getc(), getchar(), getch() and getche()_

All of these functions read a character from input and return an integer 
value. The integer is returned to accommodate a special value used to indicate 
failure. The value EOF is generally used for this purpose.

> getchar() is equal getc(stdin)

### getc(FILE* stream)
It reads a single character from a given input stream and returns the 
corresponding integer value (typically ASCII value of read character) on 
success. It returns EOF on failure.

## Format specifier (%d and %i)
A format specifier is a sequence formed by an initial percentage sign (%) 
indicates a format specifier, which is used to specify the type and format 
of the data to be retrieved from the stream and stored into the locations 
pointed by the additional arguments. In short it tell us which type of data 
to store and which type of data to print.

#### Difference
%d assume base 10 while %i auto detects the base. Therefore, both specifiers 
behaves differently while they are used with an input specifier. So, 012 would 
be 10 with %i but 12 with %d.
##### %d
%d takes integer value as signed decimal integer i.e. it takes negative values 
along with positive values but values should be in decimal otherwise it will 
print garbage value.
##### %i
%i takes integer value as integer value with decimal, hexadecimal or octal type.
To enter a value in hexadecimal format – value should be provided by preceding 
“0x” and value in octal format – value should be provided by preceding “0”.
