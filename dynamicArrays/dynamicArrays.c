#include <stdio.h>
#include <stdlib.h>

/* Memory in C is addressed in bytes 
 * Data larger than a byte will be stored in a sequence of consecutive addresses*/

/* The address of a variable is the address of the first byte that it occupies*/

/* The difference in value between each address in a sequence of variables
 * corresponds to the size in bytes of the variables' data type*/

int main() {
	int a = 10;
	int b = 11;
	int c = 12;
	int* a_ptr = &a;
	int* b_ptr = &b;
	int* c_ptr = &c;
	printf("value %d is stored at address %p\n", a, a_ptr);
	printf("value %d is stored at address %p\n", b, b_ptr);
	printf("value %d is stored at address %p\n", c, c_ptr);
	printf("The size of an integer is %zu bytes\n", sizeof(int));
	printf("The difference in value between each integer address is %d\n", (int)a_ptr - (int)b_ptr);

	printf("\n");

	char t = 'A';
	char u = 'B';
	char v = 'C';
	char* t_ptr = &t;
	char* u_ptr = &u;
	char* v_ptr = &v;
	printf("value %c is stored at address %p\n", t, t_ptr);
	printf("value %c is stored at address %p\n", u, u_ptr);
	printf("value %c is stored at address %p\n", v, v_ptr);
	printf("The size of a character is %zu bytes\n", sizeof(char));
	printf("The difference in value between each character address is %d\n", (int)t_ptr - (int)u_ptr);

	printf("\n");

	float x = 1.1;
	float y = 2.2;
	float z = 3.3;
	float* x_ptr = &x;
	float* y_ptr = &y;
	float* z_ptr = &z;
	printf("value %.1f is stored at address %p\n", x, x_ptr);
	printf("value %.1f is stored at address %p\n", y, y_ptr);
	printf("value %.1f is stored at address %p\n", z, z_ptr);
	printf("The size of a float is %zu bytes\n", sizeof(float));
	printf("The difference in value between each float address is %d\n", (int)x_ptr - (int)y_ptr);

	printf("\n");

	/* POINTER ARITHMETIC: When a pointer is added or subtracted with an integer value, the value
 	* is first multiplied by the size of the data type in bytes*/

	printf("The (address of integer c) is %p\n", c_ptr);
	printf("The (address of integer c) + 1 is %p\n", c_ptr + 1);
	printf("The (address of integer c) + 2 is %p\n", c_ptr + 2);
	printf("The size of integer c is %zu bytes\n", sizeof(c));
	printf("The difference in value between each subsequent address is %d\n", (int)(c_ptr + 1) - (int)c_ptr);

	printf("\n");

	/* Each subsequent address can be dereferenced and assigned a value */

	*(c_ptr + 1) = 20;
	*(c_ptr + 2) = 30;
	printf("The value stored in the (address of integer c) is %d\n", *c_ptr);
	printf("The value stored in the (address of integer c) + 1 is %d\n", *(c_ptr + 1));
	printf("The value stored in the (address of integer c) + 2 is %d\n", *(c_ptr + 2));

	printf("\n");

	/* BUT WAIT! The values of integers b and a have been overwritten!
	 * the addresses of b and a are the same as the (address of integer c) + 1
	 * and the (address of integer c) + 2, respectively */

	printf("The value of integer b is %d\n", b);
	printf("The value of integer a is %d\n", a);
	printf("The (address of integer c) + 1 is %p, and the address of integer b is %p\n", c_ptr + 1, b_ptr);
	printf("The (address of integer c) + 2 is %p, and the address of integer a is %p\n", c_ptr + 2, a_ptr);

	printf("\n");

	/* Accessing uninitialized pointers can yield undefined behavior
	 * Uninitialized pointers may be addressed to memory thats already used by your program or your computer system
	 * Standard practice is to assign a pointer to the address of statically or dynamically allocated memory*/

	b = 11; a = 10; //restoring the values of b and a

	c_ptr = (int* )malloc(sizeof(int) * 3);
	*c_ptr = 12;
	*(c_ptr + 1) = 20;
	*(c_ptr + 2) = 30;

	printf("The value and address of integer a is %d and %p\n", a, a_ptr);
	printf("The value and address of integer b is %d and %p\n", b, b_ptr);
	printf("The value and address of integer c is %d and %p\n", c, c_ptr);
	printf("The difference in value between the address of integers c and b is %d\n", (int)c_ptr - (int)b_ptr);

	printf("\n");

	/* The address of integer c is no longer near the address of a or b.
	 * The integers at c_ptr, the (address of integer c) + 1 and 
	 * the (address of integer c) + 2 now have their own reserved memory */

	/* The memory at the (address of integer c) + 1 and 
	 * the (address of integer c) + 2 will not be used by any other part of my 
	 * program or computer system */

	printf("The (adress of integer c) is %p, and the value stored is %d\n", c_ptr, c);
	printf("The (adress of integer c) + 1 is %p, and the value stored is %d\n", c_ptr + 1, *(c_ptr + 1));
	printf("The (adress of integer c) + 2 is %p, and the value stored is %d\n", c_ptr + 2, *(c_ptr + 2));

	free(c_ptr);
}
