#include <stdio.h>
#include <stddef.h>
#include "dynamicArraySys.h"
#include "sortAlgos.h"

int isSorted(Arr* nums) {
		for (int i = 0; i < nums->size - 1; i++) {
				if (*(nums->start + i) > *(nums->start + i + 1)) {
						return 0;
				}
		}
		return 1;
}

int testSort(SortAlgo type) {
		Arr nums0 = {};
		for (int i = 5; i > 0; i--) {
				push(&nums0, i);
		}
		for (int i = 5; i > 0; i--) {
				push(&nums0, i);
		}
		sort(type, &nums0);

		int result = 1;
		if (isSorted(&nums0)) {
				printf("Algorithm Valid\n");
				result = 0;
		}
		else {
				printf("Algorithm Failure\n");
		}
		clear(&nums0);
		return result;
}

int main() {
		printf("Return Code: %d\n", testSort(BUBBLE));
		printf("Return Code: %d\n", testSort(SELECTION));
		printf("Return Code: %d\n", testSort(INSERTION));
		printf("Return Code: %d\n", testSort(MERGE));
		printf("Return Code: %d\n", testSort(QUICK));
}
