#include <stdio.h>
#include <stddef.h>
#include "dynamicArraySys.h"

int main() {
		Arr arr0 = {};
		
		for (int i = 0; i < 5; i++) {
				enqueue(&arr0, i + 1);
				printArr(&arr0);
		}
		for (int i = 0; i < 6; i++) {
				printf("Value %d returned from pop\n", pop(&arr0));
				printArr(&arr0);
		}
		printf("\n");

		for (int i = 0; i < 3; i++) {
				insert(&arr0, 0, 3 - i);
				printArr(&arr0);
		}
		shrinkToFit(&arr0);
		insert(&arr0, 3, 5);
		printArr(&arr0);
		insert(&arr0, 3, 4);
		printArr(&arr0);
		insert(&arr0, 6, -2);
		printArr(&arr0);

		for (int i = 0; i < 6; i++) {
				printf("Value %d returned from dequeue\n", dequeue(&arr0));
				printArr(&arr0);
		}
		printf("\n");

		for (int i = 0; i < 5; i++) {
				push(&arr0, i + 1);
		}
		printArr(&arr0);
		del(&arr0, 0);
		printArr(&arr0);
		del(&arr0, 3);
		printArr(&arr0);
		del(&arr0, 1);
		printArr(&arr0);
		del(&arr0, 2);
		printArr(&arr0);

		clear(&arr0);
		printArr(&arr0);
		return 0;
}
