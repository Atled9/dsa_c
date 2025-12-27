#include <stdio.h>
#include <stdlib.h>

int* createArray(size_t size) {

	int* arr = (int* )malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		printf("Enter the value of element #%d: ", i + 1);
		scanf("%d", arr + i);
	}
	return arr;
}

void printArray(int* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int sumArray(int* arr, size_t size) {

	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += *(arr + i);
	}
	return sum;
}
int main() {
	size_t size = 0;
	printf("Enter the size of the array: ");
	scanf("%zu", &size);

	int* arr = createArray(size);
	printArray(arr, size);

	printf("The sum of all values in the array is %d", sumArray(arr, size));

	free(arr);
}
