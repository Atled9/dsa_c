#include <stdio.h>
#include <stdlib.h>

char* createArray(size_t size) {

	char* arr = (char* )malloc(sizeof(char) * size);

	for (int i = 0; i < size; i++) {
		printf("Provide a lowercase character for element #%d: ", i + 1);
		scanf(" %c", arr + i); //Use leading space to skip optional white space.
				       //This will prevent reading the newline character
				       //from the input buffer
	}

	*(arr + size) = '\0';
	return arr;
}

int getSum(char* str, size_t size) {

	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += *(str + i) - '`';
	}
	return sum;
}

int main() {
	size_t size;
	printf("Enter the size of your string: ");
	scanf("%zu", &size);

	char* arr = createArray(size);
	printf("%s", arr);
	printf("\n");

	printf("The letter sum of your string is %d", getSum(arr, size));

	free(arr);
}
