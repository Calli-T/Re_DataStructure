#include <stdio.h>

int count = 0;
float sum(float list[], int n);
float sum_summery(float list[], int n);
float rsum(float list[], int n);

int main() {

	float arr[5] = { 0.1,2.5,9.7,8.3,5.2 };
	float result = rsum(arr, 5);

	printf("%.2f %d", result, count);

	return 0;

}

float sum(float list[], int n) {

	float tempsum = 0;
	count++;
	int i;

	for (i = 0; i < n; i++) {
		count++;//for the for loop
		count++;//for assignment
		tempsum += list[i];
	}
	count++;//last execution of for
	count++; //for return

	return tempsum;
		
}

float sum_summery(float list[], int n) {
	float tempsum = 0;
	int i;
	for (i = 0; i < n; i++)
		count += 2;
	count += 3;

	return tempsum;
}

float rsum(float list[], int n) {
	count++; //for if conditional
	if (n) {
		count++; //for return & rsum invocation
		return rsum(list, n - 1) + list[n - 1];
	}
	count++;

	return list[0];
}