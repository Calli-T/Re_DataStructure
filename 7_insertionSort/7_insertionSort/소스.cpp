#include <stdio.h>

void printArr(int a[], int n) {
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insert(int e, int a[], int i) {

	a[0] = e;
	while (e < a[i])
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;

}


void insertionSort(int a[], int n) {
	int j;
	for (j = 2; j <= n; j++) {
		int temp = a[j];
		insert(temp, a, j - 1);
		printArr(a, 5);
	}
}

int main() {

	int arr[6] = {0, 5,4,3,2,1 };

	printArr(arr, 5);
	insertionSort(arr, 5);

	return 0;

}