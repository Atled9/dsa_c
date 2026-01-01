#include <stdlib.h>
#include "dynamicArraySys.h"
#include "sortAlgos.h"

void bubbleSort(Arr* nums) {
		int swapped = 0;
		int temp;

		for (int i = 1; i < nums->size - 1; i++) {
				for (int j = 0; j < nums->size - i; j++) {
						if (*(nums->start + j) > *(nums->start + j + 1)) {
								temp = *(nums->start + j);
								*(nums->start + j) = *(nums->start + j + 1);
								*(nums->start + j + 1) = temp;

								swapped = 1;
						}
				}
				if (!swapped) {
						return;
				}
				swapped = 0;
		}
}

void selectionSort(Arr* nums) {
        int temp;
        int minValInd;

        for (int i = 0; i < nums->size - 1; i++) {
                minValInd = i;

                for (int j = i + 1; j < nums->size; j++) {
                        if (*(nums->start + minValInd) > *(nums->start + j)) {
                                minValInd = j;
                        }
                }
                temp = *(nums->start + i);
                *(nums->start + i) = *(nums->start + minValInd);
                *(nums->start + minValInd) = temp;
        }
}

void insertionSort(Arr* nums) {
        int currentVal;
        int j;

        for (int i = 1; i < nums->size; i++) {
                currentVal = *(nums->start + i);
                j = i - 1;

                while (*(nums->start + j) > currentVal && j >= 0) {
                        *(nums->start + j + 1) = *(nums->start + j);
                        j--;
                }
                *(nums->start + j + 1) = currentVal;
        }
}

void merge(Arr* nums, int l, int mid, int r) {
        size_t sizeLeft = mid - l + 1;
        size_t sizeRight = r - mid;

        int* lArr = malloc(sizeLeft * sizeof(int));
        int* rArr = malloc(sizeRight * sizeof(int));

        int i, j, k;

        for (i = 0; i < sizeLeft; i++) {
                *(lArr + i) = *(nums->start + l + i);
        }
        for (i = 0; i < sizeRight; i++) {
                *(rArr + i) = *(nums->start + mid + 1 + i);
        }

        i = j = 0; k = l;
        while (i < sizeLeft && j < sizeRight) {
                if (*(lArr + i) <= *(rArr + j)) {
                        *(nums->start + k) = *(lArr + i);
                        i++;
                }
                else {
                        *(nums->start + k) = *(rArr + j);
                        j++;
                }
                k++;
        }
        while (i < sizeLeft) {
                *(nums->start + k) = *(lArr + i);
                i++;
                k++;
        }
        while (j < sizeRight) {
                *(nums->start + k) = *(rArr + j);
                j++;
                k++;
        }

        free(lArr); free(rArr);
}

void mergeSort_h(Arr* nums, int l, int r) {
        if (l >= r) {
                return;
        }

        int mid = l + ((r - l) / 2);

        mergeSort_h(nums, l, mid);
        mergeSort_h(nums, mid + 1, r);
        merge(nums, l, mid, r);
}

void mergeSort(Arr* nums) {
        mergeSort_h(nums, 0, nums->size - 1);
}

int partition(Arr* nums, int lo, int hi) {
        int pivotVal = *(nums->start + hi);
        int pivot = lo;

        int temp;
        for (int i = lo; i < hi; i++) {
                /* less than or equal to puts like values next to each other earlier on
                 * reducing computational workload */
                if (*(nums->start + i) <= pivotVal) {
                        temp = *(nums->start + i);
                        *(nums->start + i) = *(nums->start + pivot);
                        *(nums->start + pivot) = temp;

                        pivot++;
                }
        }
        temp = *(nums->start + hi);
        *(nums->start + hi) = *(nums->start + pivot);
        *(nums->start + pivot) = temp;

        return pivot;
}

void quickSort_h(Arr* nums, int lo, int hi) {
        if (lo >= hi || lo < 0) {
                return;
        }

        int pivot = partition(nums, lo, hi);

        quickSort_h(nums, lo, pivot - 1);
        quickSort_h(nums, pivot + 1, hi);
}

void quickSort(Arr* nums) {
        quickSort_h(nums, 0, nums->size - 1);
}

void sort(SortAlgo type, Arr* nums) {
		switch(type) {
				case 0:
						bubbleSort(nums);
						break;
				case 1:
						selectionSort(nums);
						break;
				case 2:
						insertionSort(nums);
						break;
				case 3:
						mergeSort(nums);
						break;
				case 4:
						quickSort(nums);
						break;
		}
}
