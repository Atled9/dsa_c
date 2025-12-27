#include <stdio.h>
#include <stdlib.h>

int main() {
	char a = 'H';
	char b = 'i';
	char c = '!';
	char* a_ptr = &a;
	char* b_ptr = &b;
	char* c_ptr = &c;
	printf("The value of character a is %c, and the address is %p\n", a, a_ptr);
	printf("The value of character b is %c, and the address is %p\n", b, b_ptr);
	printf("The value of character c is %c, and the address is %p\n", c, c_ptr);

	printf("\n");

	*(c_ptr + 1) = 'y';
	*(c_ptr + 2) = 'o';
	printf("The value of *(c_ptr + 1) is %c, and the address is %p\n", *(c_ptr + 1), c_ptr + 1);
	printf("The value of *(c_ptr + 2) is %c, and the address is %p\n", *(c_ptr + 2), c_ptr + 2);

	printf("\n");

	/* characters b and a have benn overwritten
	 * b and a share the same address as (c_ptr + 1) and (c_ptr + 2) respectively */

	printf("The value of character b is %c, and the address is %p\n", b, b_ptr);
	printf("The value of character a is %c, and the address is %p\n", a, a_ptr);

	printf("\n");

	a = 'H'; b = 'i'; //restoring the values of b and a
	
	c_ptr = (char* )malloc(3 * sizeof(char));
	*c_ptr = '!';
	*(c_ptr + 1) = 'y';
	*(c_ptr + 2) = 'o';

	printf("The value of character a is %c, and the address is %p\n", a, a_ptr);
	printf("The value of character b is %c, and the address is %p\n", b, b_ptr);
	printf("The value of character c is %c, and the address is %p\n", c, c_ptr);
	printf("The value of *(c_ptr + 1) is %c, and the address is %p\n", *(c_ptr + 1), c_ptr + 1);
	printf("The value of *(c_ptr + 2) is %c, and the address is %p\n", *(c_ptr + 2), c_ptr + 2);

	printf("\n");
	free(c_ptr);

	/* The address of character c is no longer near the addresses of b or a
	 * the variables at c_ptr, (c_ptr + 1), and (c_ptr + 2) are now inside
	 * their own reserved memory */ 

	/* STRINGS */

	char* msg = (char* )malloc(4 * sizeof(char)); //Allocate memory for the message to avoid undefined behavior
	*msg = 'H';
	*(msg + 1) = 'i';
	*(msg + 2) = '!';
	*(msg + 3) = '\0'; //include the null terminating character at the end of your string
			   //the null terminating character denotes the end of a string

	for (int i = 0; i < 3; i++) {
		printf("%c", *(msg + i));
	}
	printf("\n");

	/* Array can be handled as a string */
	printf("%s", msg);

	free(msg);
	printf("\n\n");

	char* msg2 = "test"; // STRING LITERAL: Memory is already allocated. Static sized immutable array (not dynamic)

	/* Values can still be accessed using pointer arithmetic */
	for (int i = 0; i < 4; i++) {
		printf("%c", *(msg2 + i));
	}
	printf("\n");

	/* Array can be handled as a string */
	printf("%s", msg2);
	
	/* No need to free. String literals are freed at the end of the program's lifetime */
}
