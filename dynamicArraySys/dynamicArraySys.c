#include <stdlib.h>
#include <stdio.h>
#include "dynamicArraySys.h"

void printArr(Arr* nums) {
		printf("Values in the array: ");

		for (int i = 0; i < nums->size; i++) {
				printf("%d ", *(nums->start + i));
		}
		printf("\n");

		printf("The size is %zu, and the capacity is %zu\n", nums->size, nums->capacity);
}

void expand(Arr* nums) {
		if (nums->capacity == 0) {
				nums->start = malloc(sizeof(int));
				nums->capacity = 1;
		}
		else {
				nums->start = realloc(nums->start, 2 * nums->capacity * sizeof(int));
				nums->capacity *= 2;
		}
}
void shrinkToFit(Arr* nums) {
		nums->start = realloc(nums->start, nums->size * sizeof(int));
		nums->capacity = nums->size;
}
void clear(Arr* nums) {
		free(nums->start);
		nums->size = 0;
		nums->capacity = 0;
}

void push(Arr* nums, int num) {
		if (nums->capacity <= nums->size) {
				expand(nums);
		}

		nums->size++;
		*(nums->start + nums->size - 1) = num;
}
void enqueue(Arr* nums, int num) {
		push(nums, num);
}
int pop(Arr* nums) {
		if (nums->size == 0) {
				printf("Array is empty\n");
				return -1;
		}
		nums->size--;
		return *(nums->start + nums->size);
}
int dequeue(Arr* nums) {
		if (nums->size == 0) {
				printf("Array is empty\n");
				return -1;
		}
		int val = *(nums->start);

		for (int i = 0; i < nums->size - 1; i++) {
				*(nums->start + i) = *(nums->start + i + 1);
		}
		nums->size--;
		return val;
}

void insert(Arr* nums, int ind, int num) {
		if (ind < 0 || ind > nums->size) {
				printf("Invalid index\n");
				return;
		}

		if (nums->capacity <= nums->size) {
				expand(nums);
		}

		for (int i = nums->size; i > ind; i--) {
				*(nums->start + i) = *(nums->start + i - 1);
		}
		*(nums->start + ind) = num;
		nums->size++;
}

void del(Arr* nums, int ind) {
		if (nums->size == 0) {
				printf("Array is empty\n");
				return;
		}
		if (ind < 0 || ind >= nums->size) {
				printf("Invalid index\n");
				return;
		}

		for (int i = ind; i < nums->size - 1; i++) {
				*(nums->start + i) = *(nums->start + i + 1);
		}
		nums->size--;
}
