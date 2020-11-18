#include <stdio.h>
#define MAX_SIZE 15

int main() {
	int square[MAX_SIZE][MAX_SIZE];
	int i, j, row, column;
	int size;
	int count;

	printf("Enter the  size of the square: ");
	scanf_s("%d", &size);
	if (size<1 || size> MAX_SIZE + 1) {
		printf("Error! Size is out of range\n");
		return 0;
	}
	if (!(size % 2)) {
		printf("Error! Size is even\n");
		return 0;
	}
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			square[i][j] = 0;
	square[0][(size - 1) / 2] = 1;
	i = 0;
	j = (size - 1) / 2;
	for (count = 2; count <= size * size; count++) {
		row = (i - 1 < 0) ? (size - 1) : (i - 1);
		column = (j - 1 < 0) ? (size - 1) : (j - 1);
		if (square[row][column] != 0) {
			i = (++i) % size;
		}
		else {
			i = row;
			j = column;
		}
		square[i][j] = count;
	}

	printf("Magic Square of size %d : \n\n", size);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%5d", square[i][j]);
		printf("\n");
	}
	printf("\n\n");

	return 0;
}