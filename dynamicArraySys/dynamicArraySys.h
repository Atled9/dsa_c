typedef struct {
		int* start;
		size_t size;
		size_t capacity;
} Arr;

void printArr(Arr* nums);

void expand(Arr* nums);
void shrinkToFit(Arr* nums);
void clear(Arr* nums);

void push(Arr* nums, int num);
void enqueue(Arr* nums, int num);
int pop(Arr* nums);
int dequeue(Arr* nums);

void insert(Arr* nums, int ind, int num);
void del(Arr* nums, int ind);
