#include <stdio.h>

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void quickSort(int a[], int left, int right) {
	
	int pivot, i, j;
	int temp;

	if (left < right) {

		i = left; j = right + 1;
		pivot = a[left];

		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			//printf("\n%d %d\n", i, j);
			if (i < j) {
				//printf("\n a[i]: %d a[j]: %d pivot:%d \n", a[i], a[j], pivot);
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		//printf("\n i: %d, j: %d \n", i, j);
		//printf("\n a[left]: %d a[j]: %d pivot:%d \n", a[left], a[j], pivot);
		temp = a[j];
		a[j] = a[left];
		a[left] = temp;

		//printf("%d:%d\n", left, right);

		printArr(a, 10);

		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);

	}

}

int main() {

	int list[] = { 26, 5, 37, 1 , 61, 11, 59, 15, 48, 19 };

	printArr(list, 10);
	quickSort(list, 0, 9);
	//printArr(list, 10);

	return 0;

}