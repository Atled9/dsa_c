#include <stdlib.h>
#include <stdio.h>
#include "dynamicArraySys.h"
#include "searchAlgos.h"

int testSearch(SearchAlgo type) {
		Arr nums0 = {malloc(5 * sizeof(int)), 5, 5};
		Arr nums1 = {malloc(5 * sizeof(int)), 5, 5};

		for (int i = 0; i < nums0.size; i++) {
				*(nums0.start + i) = i + 1;
				*(nums1.start + i) = i + 1;
		}
		for (int i = 2; i < nums1.size; i++) {
				*(nums1.start + i) += 1;
		}

		int result = 0;

		if (search(type, &nums0, 3) == -2) {
				printf("Invalid type\n");
				return 2;
		}

		if (search(type, &nums0, 3) != 2) {
				printf("Failed at internal value search\n");
				result = 1;
		}
		if (search(type, &nums0, 1) != 0) {
				printf("Failed at lower boundary search\n");
				result = 1;
		}
		if (search(type, &nums0, 5) != 4) {
				printf("Failed at opper boundary search\n");
				result = 1;
		}
		if (search(type, &nums0, 0) != -1) {
				printf("Failed at lower non-existent value search\n");
				result = 1;
		}
		if (search(type, &nums0, 6) != -1) {
				printf("Failed at upper non-existent value search\n");
				result = 1;
		}
		if (search(type, &nums1, 3) != -1) {
				printf("Failed at internal non-existent value search\n");
				result = 1;
		}

		if (result == 0) {
				printf("All tests passed!\n");
		}

		clear(&nums0); clear(&nums1);
		return result;
}

int main() {
		printf("Return Code: %d\n", testSearch(LINEAR));
		printf("Return Code: %d\n", testSearch(BINARY));
		printf("Return Code: %d\n", testSearch(INTERPOLATION));
		return 0;
}
