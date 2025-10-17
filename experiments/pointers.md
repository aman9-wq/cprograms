Pointers is the variables that have to contain address.

Pointers.c declare pointers of three types(int, char, bool). printf("%p") with &variable as argument prints the address where variable that points to some specific address is stored. printf("%p") with variable prints what address is pointed by variable. printf("%p") with (* variable) prints the content of pointed address.

Pointers.c prints the addresses in 8 bytes and their representations in 4 bytes for different types. Something tells me that all format specifiers(except %p) prints the last 4 bytes of addresses.

In pointers.c printf("%p %p %p\n", &x, x, * x); lead to some issues about why %p with (* x) prints some specific value like 0xfa1e0ff3. This issue immediately created pointers2-pointers5 files that contain answer to this question. Briefly: this const-like value appears because of following print function with arguments like &arr, arr, (* arr). That is if within following printf function there will be another pointer, then * x will not change from one exectuion to the next(see pointers2-pointers5).

The next issue is related to the representation of negative numbers in binary. In binary(or executable) the negative numbers are started from the address like 0xfffff. In my opinion it is because of there are no hexadecimals with - symbol and also it is easier to assign negative numbers to any big addresses, which are usually have no use. In pointers.c outputs from 1 to 4 line outputs some garbage values(addresses and what it include).
