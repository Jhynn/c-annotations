# Sets ()

## Set 1 - Arithmetic operators.

<table>
<tr>
    <th> Unary, logical and ternary. </th>
    <th> Arithmetic and Logical.     </th>
</tr>
<tr>
    <td>
        | Symbol |  Type      |
        |:------:|-----------:|
        | +      | Arithmetic |
        | -      | Arithmetic |
        | *      | Arithmetic |
        | /      | Arithmetic |
        | %      | Arithmetic |
        | &&     | Logical    |
        | \|\|   | Logical    |
        | !      | Logical    |
    </td>
    <td>
        | Symbol |  Type      |
        |:------:|-----------:|
        | +      | Unary      |
        | -      | Unary      |
        | <      | Relational |
        | <=     | Relational |
        | ==     | Relational |
        | !=     | Relational |
        | >      | Relational |
        | >=     | Relational |
    </td>
</tr>
</table>

## Some observations about ternary operator.

### A ternary operator has the following form:

> exp1 ? exp2 : exp3;

The expression *exp1* will be evaluated always. Execution of *exp2* and *exp3* 
depends on the outcome of *exp1*. If the outcome of *exp1* is **non zero** 
*exp2* **will be evaluated**, **otherwise** *exp3* **will be evaluated**.

### Return Type:

It is another interesting fact. The ternary operator has return type. 
The return type **depends** on *exp2*, and **convertibility** of *exp3* 
into *exp2* as per usual\overloaded conversion rules. If they are not 
convertible, the compiler throws an error. See the examples below:

The following program compiles without any error. The return type of ternary 
expression is expected to be **float** (as that of *exp2*) and *exp3* 
(i.e., literal zero – **int** type) is implicitly convertible to **float**.

```C++
#include <iostream>

using namespace std;

int
main(void) {
    int test = 0;
    float fvalue = 3.111f;

    cout << (test ? fvalue : 0) << endl;

    return 0;
} 
```

The following program will not compile, because the compiler is unable to find 
return type of ternary expression or implicit conversion is unavailable between
*exp2* (**char** array) and *exp3* (**int**).

```C++
#include <iostream>
using namespace std;

int
main(void) {
    int test = 0;
    cout << test ? "A String" : 0 << endl;

    return 0;
} 
```

The following program *may* compile, or but fails at runtime. The return type 
of ternary expression is bounded to type (**char***), yet the expression 
returns **int**, hence the program fails. Literally, the program tries to print
string at *0th* address at runtime.

```C++
#include <iostream>

using namespace std;

int
main(void) {
    int test = 0;
    cout << (test ? "A String" : 0) << endl;

    return 0;
}
```

We can observe that *exp2* is considered as output type and *exp3* will be 
converted into *exp2* at runtime. If the conversion is implicit the compiler 
inserts stubs for conversion. If the conversion is explicit the compiler throws
an error. If any compiler misses to catch such error, the program may fail at 
runtime.

## Best Practice:

It is the power of C++ type system that avoids such bugs. Make sure both the 
expressions *exp2* and *exp3* return same type or atleast safely convertible 
types. We can see other idioms like C++ convert union for safe conversion.
