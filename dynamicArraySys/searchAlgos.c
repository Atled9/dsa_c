#include <stddef.h>
#include "dynamicArraySys.h"
#include "searchAlgos.h"

int linearSearch(Arr* nums, int val) {
		for (int i = 0; i < nums->size; i++) {
				if (*(nums->start + i) == val) {
						return i;
				}
		}
		return -1;
}

int binarySearch(Arr* nums, int val) {
		int lo = 0;
		int hi = nums->size - 1;
		int mid;

		while (lo <= hi) {
				mid = (lo + hi) / 2;

				if (*(nums->start + mid) == val) {
						return mid;
				}

				if (*(nums->start + mid) < val) {
						lo = mid + 1;
				}
				else {
						hi = mid - 1;
				}
		}
		return -1;
}


int interpolationSearch(Arr* nums, int val) {
		int lo = 0;
		int hi = nums->size - 1;
		int mid;

		while (lo <= hi && val >= *(nums->start + lo) && val <= *(nums->start + hi)) {
				mid = lo + (val - *(nums->start + lo)) * ((hi - lo) / (*(nums->start + hi) - *(nums->start + lo)));

				if (*(nums->start + mid) == val) {
						return mid;
				}

				if (*(nums->start + mid) < val) {
						lo = mid + 1;
				}
				else {
						hi = mid - 1;
				}
		}
		return -1;
}

int search(SearchAlgo type, Arr* nums, int val) {
		switch(type) {
				case 0:
						return linearSearch(nums, val);
				case 1:
						return binarySearch(nums, val);
				case 2:
						return interpolationSearch(nums, val);
		}
		return -2;
}
