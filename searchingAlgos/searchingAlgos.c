#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memcpy()

typedef struct {
	int* arr;
	size_t size;
} Nums;

typedef enum {
	LINEAR,
	BINARY,
	INTERPOLATION,
	BINARY_R,
	INTERPOLATION_R
} SearchAlgo;

void printNums(Nums* numArr) {
	printf("Values in array: ");
	for (int i = 0; i < numArr->size; i++) {
		printf("%d ", *(numArr->arr + i));
	}
	printf("\nThe size of the array is %d\n", numArr->size);
}

int linearSearch(Nums* numArr, int val) {
	int index = -1;
	for (int i = 0; i < numArr->size; i++) {
		if (*(numArr->arr + i) == val) {
			index = i;
		}
	}
	return index;
}

int binarySearch(Nums* numArr, int val) {
	int lo = 0;
	int hi = numArr->size - 1;
	int mid = -1;

	while(lo <= hi) {
		mid = lo + ((hi - lo) / 2);

		if (*(numArr->arr + mid) == val) {
			return mid;
		}
		else if (*(numArr->arr + mid) < val) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return -1;
}

int interpolationSearch(Nums* numArr, int val) {
	int lo = 0;
	int hi = numArr->size - 1;
	int mid = -1;

	while(lo <= hi && val >= *(numArr->arr + lo) && val <= *(numArr->arr + hi)) {
		mid = lo + (val - *(numArr->arr + lo)) * ((hi - lo) / (*(numArr->arr + hi) - *(numArr->arr + lo)));

		if (*(numArr->arr + mid) == val) {
			return mid;
		}
		else if (*(numArr->arr + mid) < val) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return -1;
}

int binarySearch_rh(Nums* numArr, int lo, int hi, int val) {
	if (lo > hi) {
		return -1;
	}

	int mid = lo + ((hi - lo) / 2);

	if (*(numArr->arr + mid) == val) {
		return mid;
	}
	else if (*(numArr->arr + mid) < val) {
		return binarySearch_rh(numArr, mid + 1, hi, val);
	}
	else {
		return binarySearch_rh(numArr, lo, mid - 1, val);
	}
}

int binarySearch_r(Nums* numArr, int val) {
	return binarySearch_rh(numArr, 0, numArr->size - 1, val);
}

int interpolationSearch_rh(Nums* numArr, int lo, int hi, int val) {
	if (lo > hi || val < *(numArr->arr + lo) || val > *(numArr->arr + hi)) {
		return -1;
	}

	int mid = lo + (val - *(numArr->arr + lo)) * ((hi - lo) / (*(numArr->arr + hi) - *(numArr->arr + lo)));

	if (*(numArr->arr + mid) == val) {
		return mid;
	}
	else if (*(numArr->arr + mid) < val) {
		return interpolationSearch_rh(numArr, mid + 1, hi, val);
	}
	else {
		return interpolationSearch_rh(numArr, lo, mid - 1, val);
	}
}

int interpolationSearch_r(Nums* numArr, int val) {
	return interpolationSearch_rh(numArr, 0, numArr->size - 1, val);
}

int search(SearchAlgo type, Nums* numArr, int val) {
	switch(type) {
		case 0:
			return linearSearch(numArr, val);
		case 1:
			return binarySearch(numArr, val);
		case 2:
			return interpolationSearch(numArr, val);
		case 3:
			return binarySearch_r(numArr, val);
		case 4:
			return interpolationSearch_r(numArr, val);
	}
	/* return -1 for non-existent value, or -2 for invalid type */
	printf("Invalid Search Type\n");
	return -2;
}

/* (non-zero) and 0 used in place of true and false */
/* int type value treated as boolean */
int testSearchAlgo(SearchAlgo type) {
	Nums a0 = {malloc(5 * sizeof(int)), 5};
	Nums a1 = {malloc(5 * sizeof(int)), 5};

	for (int i = 0; i < a0.size; i++) {
		*(a0.arr + i) = i + 1;
	}
	memcpy(a1.arr, a0.arr, a0.size * sizeof(int));

	for (int i = 2; i < a1.size; i++) {
		*(a1.arr + i) += 1;
	}

	int result = 1;
	if (search(type, &a0, 3) != 2) {
		printf("failed at internal index\n");
		result = 0;
	}
	if (search(type, &a0, 1) != 0) {	
		printf("failed at lower bound index\n");
		result = 0;
	}
	if (search(type, &a0, 5) != 4) {
		printf("failed at upper bound index\n");
		result = 0;
	}
	if (search(type, &a0, 0) != -1) {
		printf("failed at low out-of-boud non-existent value\n");
		result = 0;
	}
	if (search(type, &a0, 6) != -1) {
		printf("failed at upper out-of-bound non-existent value\n");
		result = 0;
	}
	if (search(type, &a1, 3) != -1) {
		printf("failed at internal non-existent value\n");
		result = 0;
	}

	if (result) {
		printf("All tests passed\n");
	}

	free(a0.arr); free(a1.arr);
	return result;
}

int main() {
	printf("%d\n", testSearchAlgo(LINEAR));
	printf("%d\n", testSearchAlgo(BINARY));
	printf("%d\n", testSearchAlgo(INTERPOLATION));
	printf("%d\n", testSearchAlgo(BINARY_R));
	printf("%d\n", testSearchAlgo(INTERPOLATION_R));
	return 0;
}
