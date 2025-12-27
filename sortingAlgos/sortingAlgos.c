#include <stdio.h>
#include <stdlib.h>

typedef struct {
		int* arr;
		size_t size;
} Nums;

typedef enum {
		BUBBLE,
		SELECTION,
		INSERTION,
		MERGE,
		QUICK,
		MERGE_ITER,
		QUICK_ITER
} SortAlgo;

void printNums(Nums* numArr) {
		printf("Values in array: ");
		for (int i = 0; i < numArr->size; i++) {
				printf("%d ", *(numArr->arr + i));
		}
		printf("\nThe size of the array is %zu\n", numArr->size);
}

void bubbleSort(Nums* numArr) {
		int temp;

		for (int i = 0; i < numArr->size - 1; i++) {
				for (int j = 0; j < numArr->size - i; j++) {
						if (*(numArr->arr + j) > *(numArr->arr + j + 1)) {
								temp = *(numArr->arr + j);
								*(numArr->arr + j) = *(numArr->arr + j + 1);
								*(numArr->arr + j + 1) = temp;
						}
				}
		}	
}

void selectionSort(Nums* numArr) {
		int temp;
		int minValInd;

		for (int i = 0; i < numArr->size - 1; i++) {
				minValInd = i;

				for (int j = i + 1; j < numArr->size; j++) {
						if (*(numArr->arr + minValInd) > *(numArr->arr + j)) {
								minValInd = j;
						}
				}
				temp = *(numArr->arr + i);
				*(numArr->arr + i) = *(numArr->arr + minValInd);
				*(numArr->arr + minValInd) = temp;
		}
}

void insertionSort(Nums* numArr) {
		int currentVal;
		int j;

		for (int i = 1; i < numArr->size; i++) {
				currentVal = *(numArr->arr + i);
				j = i - 1;

				while (*(numArr->arr + j) > currentVal && j >= 0) {
						*(numArr->arr + j + 1) = *(numArr->arr + j);
						j--;
				}
				*(numArr->arr + j + 1) = currentVal;
		}
}

void merge(Nums* numArr, int l, int mid, int r) {
		size_t sizeLeft = mid - l + 1;
		size_t sizeRight = r - mid;

		int* lArr = malloc(sizeLeft * sizeof(int));
		int* rArr = malloc(sizeRight * sizeof(int));

		int i, j, k;

		for (i = 0; i < sizeLeft; i++) {
				*(lArr + i) = *(numArr->arr + l + i);
		}
		for (i = 0; i < sizeRight; i++) {
				*(rArr + i) = *(numArr->arr + mid + 1 + i);
		}

		i = j = 0; k = l;
		while (i < sizeLeft && j < sizeRight) {
				if (*(lArr + i) <= *(rArr + j)) {
						*(numArr->arr + k) = *(lArr + i);
						i++;
				}
				else {
						*(numArr->arr + k) = *(rArr + j);
						j++;
				}
				k++;
		}
		while (i < sizeLeft) {
				*(numArr->arr + k) = *(lArr + i);
				i++;
				k++;
		}
		while (j < sizeRight) {
				*(numArr->arr + k) = *(rArr + j);
				j++;
				k++;
		}

		free(lArr); free(rArr);
}

void mergeSort_h(Nums* numArr, int l, int r) {
		if (l >= r) {
				return;
		}

		int mid = l + ((r - l) / 2);
		
		mergeSort_h(numArr, l, mid);
		mergeSort_h(numArr, mid + 1, r);
		merge(numArr, l, mid, r);
}

void mergeSort(Nums* numArr) {
		mergeSort_h(numArr, 0, numArr->size - 1);
}

int partition(Nums* numArr, int lo, int hi) {
		int pivotVal = *(numArr->arr + hi);
		int pivot = lo;

		int temp;
		for (int i = lo; i < hi; i++) {
				/* less than or equal to puts like values next to each other earlier on
				 * reducing computational workload */
				if (*(numArr->arr + i) <= pivotVal) {
						temp = *(numArr->arr + i);
						*(numArr->arr + i) = *(numArr->arr + pivot);
						*(numArr->arr + pivot) = temp;

						pivot++;
				}
		}
		temp = *(numArr->arr + hi);
		*(numArr->arr + hi) = *(numArr->arr + pivot);
		*(numArr->arr + pivot) = temp;

		return pivot;
}

void quickSort_h(Nums* numArr, int lo, int hi) {
		if (lo >= hi || lo < 0) {
				return;
		}
		
		int pivot = partition(numArr, lo, hi);

		quickSort_h(numArr, lo, pivot - 1);
		quickSort_h(numArr, pivot + 1, hi);
}

void quickSort(Nums* numArr) {
		quickSort_h(numArr, 0, numArr->size - 1);
}

void sort(SortAlgo type, Nums* numArr) {
		switch(type) {
				case 0:
						bubbleSort(numArr); 
						return;
				case 1:
						selectionSort(numArr);
						return;
				case 2:
						insertionSort(numArr);
						return;
				case 3:
						mergeSort(numArr);
						return;
				case 4:
						quickSort(numArr);
						return;
		}
		printf("Invalid Sort Type\n");
}

/* 1 means true, 0 means false */
int isSorted(Nums* numArr) {
		for (int i = 0; i < numArr->size - 1; i++) {
				if (*(numArr->arr + i) > *(numArr->arr + i + 1)) {
						return 0;
				}
		}
		return 1;
}
/* 0 means no error, 1 means failure */
int testSortAlgo(SortAlgo type) {
		Nums a0 = {malloc(10 * sizeof(int)), 10};
		for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 5; j++) {
						*(a0.arr + (i * 5) + j) = 5 - j;
				}	
		}
		printNums(&a0);

		sort(type, &a0);
		printNums(&a0);

		int result = 0;
		if (!isSorted(&a0)) { 
				result = 1;
				printf("sort_failure\n");
		}
		else {
				printf("sort_success\n");
		}

		printf("\n");
		free(a0.arr);
		return result;
}

int main() {
		printf("%d\n", testSortAlgo(BUBBLE));
		printf("%d\n", testSortAlgo(SELECTION));
		printf("%d\n", testSortAlgo(INSERTION));
		printf("%d\n", testSortAlgo(MERGE));
		printf("%d\n", testSortAlgo(QUICK));

		return 0;
}
