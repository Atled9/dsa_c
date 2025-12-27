#include <stdio.h>
#include <stdlib.h>

int btoi(char* bStr) {
	int value = 0;
	int iter = 0;

	while(*(bStr + iter)) {
		value = (value * 2) + (*(bStr + iter) - '0');
		iter++;
	}
	return value;
}

int btod(int bNum) {
	int value = 0;
	int powerVal = 1;

	while (bNum) {
		value += (bNum % 10) * powerVal;
		powerVal *= 2;
		bNum /= 10;
	}
	return value;
}

int main() {
	char bStr[] = "10010";
	int bVal = 10011;

	printf("The string value is %s\n", bStr);
	printf("The integer value is %d\n", btoi(bStr));
	printf("\n");

	printf("The binary value is %d\n", bVal);
	printf("The decimal value is %d\n", btod(bVal));
}
