#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define compare(x, y) ((x) < (y) ? -1 : ((x)==(y)) ? 0: 1)

int binsearch(int list[], int key, int left, int right);
void sort(int[], int);
int recursiveBinsearch(int list[], int key, int left, int right);

int main(void) {

	int i, n, list[MAX_SIZE];
	int ans = 0;

	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);
	if (n<1 || n>MAX_SIZE) {
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}
	sort(list, n);
	printf("\n Sorted array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	ans = binsearch(list, 500, 0, n - 1);
	printf("%d번째 위치\n", ans + 1);

	return 0;

}

void sort(int list[], int n) {
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}

}

int binsearch(int list[], int key, int left, int right) {
	
	int middle;
	
	while (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], key)) {
		case -1: left = middle + 1;
			break;
		case 0:return middle;
		case 1: right = middle - 1;
		}
	}

	return -1;

}

int recursiveBinsearch(int list[], int key, int left, int right) {
	int middle;

	if (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], key)) {
		case -1: return recursiveBinsearch(list, key, middle + 1, right); break;
		case 0: return middle; break;
		case 1: return recursiveBinsearch(list, key, left, middle - 1); break;
		}
	}
	else {
		return -1;
	}
}