typedef enum {
		LINEAR,
		BINARY,
		INTERPOLATION
} SearchAlgo;

int search(SearchAlgo type, Arr* nums, int val);
