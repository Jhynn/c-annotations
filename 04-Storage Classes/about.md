# Storage Classes:
Are used __to describe the features of a variable/function.__ These features 
basically include the scope, visibility and life-time which help us to trace 
the existence of a particular variable during the runtime of a program.

Storage Specifier | Storage | Initial value |    Scope     | Life         |
------------------|:-------:|:-------------:|:------------:|-------------:|
**_auto_**        | Stack   | Garbage       | Within block | End of block |
**_extern_**      | Data segment | Zero     | Global multiple files | Till end of program
**_static_**      | Data segment | Zero     | Within block | Till end of program
**_register_**    | CPU Register | Garbage  | Within block | End of block

1. __auto:__ This is the default storage class for all the variables declared 
inside a function or a block. Auto variables can be only accessed within the 
block/function they have been declared and not outside them 
(which defines their scope). However, they can be accessed outside their 
scope as well using the concept of pointers by pointing to the exact 
memory location where the variables resides.

2. __extern:__ Extern storage class simply tells us that the variable is 
defined elsewhere and not within the same block where it is used. Basically, 
the value is assigned to it in a different block and this can be 
overwritten/changed in a different block as well. So an extern variable is 
nothing but a global variable initialized with a legal value where it is 
declared in order to be used elsewhere. It can be accessed within any 
function/block. Also, a normal global variable can be made extern as well by 
placing the ‘extern’ keyword before its declaration/definition in any 
function/block. This basically signifies that we are not initializing a new 
variable but instead we are using/accessing the global variable only. 
The main purpose of using extern variables is that they can be accessed 
between two different files which are part of a large program.

3. __static:__ Static variables have a property of preserving their value 
even after they are out of their scope! Hence, static variables preserve the 
value of their last use in their scope. So we can say that they are 
initialized only once and exist till the termination of the program. Thus, no 
new memory is allocated because they are not re-declared. Their scope is 
local to the function to which they were defined. Global static variables can 
be accessed anywhere in the program.

4. __register:__ This storage class declares register variables which have the 
same functionality as that of the auto variables. The only difference is that 
the compiler tries to store these variables in the register of the 
microprocessor if a free register is available. This makes the use of register 
variables to be much faster than that of the variables stored in the memory 
during the runtime of the program. If a free register is not available, these 
are then stored in the memory only. Usually few variables which are to be 
accessed very frequently in a program are declared with the register keyword 
which improves the running time of the program. An important and interesting 
point to be noted here is that we cannot obtain the address of a register 
variable using pointers.

## syntax:
```C
<storage_class> <var_data_type> var_name; 
```



###### [GeeksForGeeks](https://www.geeksforgeeks.org/storage-classes-in-c/)
