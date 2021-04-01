#include <stdio.h>
#include <stdlib.h>

//���� �迭���� �ϳ� �� ū�� ���� ���������� �ϳ��� �� ������ ���� �迭�� �������� �ٳִ� �Լ�
//�׳� ������ ����
void merge(int list[], int sorted[], int i, int m, int n) {
	int j = m + 1, k = i;

	//printf("list[i]: %d, list[j]: %d\n%d %d\n", list[i], list[j], i, n);

	//printf("%d, %d, %d, %d", i, j, m, n);
	while (i <= m && j <= n) {
		//printf("list[i]: %d, list[j]: %d", list[i], list[j]);
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > m)
		for (; j <= n; j++) sorted[k++] = list[j];
	else
		for (; i <= m; i++) sorted[k++] = list[i];
}

void merge_pass(int list[], int sorted[], int n, int length) {
	//list�� �����迭 sorted�� ���� �迭, n�� ����, length�� ���� ��������
	int i, j;
	//������ 0�����ϸ鼭, �ִ� �迭 ������ n-2*�������� ���� �ϰ�
	//�ѹ��� 2����迭��ŭ merge������ 2�������̸�ŭ �ǳʶڴ�
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge(list, sorted, i, i + length - 1, i + 2 * length - 1);

	//????? ������ ����
	if (i + length < n)
		merge(list, sorted, i, i + length - 1, n - 1);
	else
		for (j = i; j < n; j++)
			sorted[j] = list[j];
}

void merge_sort(int list[], int n) {
	int length = 1;
	int extra[100];

	while (length < n) {
		//2n�谡 �ƴ� ���� �迭������ ���߱����� 2���� �ǽ��ϴ°��ϱ�
		merge_pass(list, extra, n, length);
		length *= 2;
		//���������� list�� ����Ѵ�
		merge_pass(extra, list, n, length);
		length *= 2;
	}
}

int main() {
	int arr[] = {26,5,77,1,61,11,59, 15, 48, 19 };
	/*
	int arr[10];
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &arr[i]);
	}
	*/
	int n = 10;
	
	merge_sort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/*
5 5
3 3 6 8 10
1 2 3 10 12
*/

/*
int m, n, o;
	int i;
	scanf_s("%d %d", &m, &n);
	o = m + n;
	int* p1 = (int*)malloc(sizeof(int) * m);
	int* p2 = (int*)malloc(sizeof(int) * n);
	int* p3 = (int*)malloc(sizeof(int) * (m + n));

	int* ans = (int*)malloc(sizeof(int) * (m + n));

	
for (i = 0; i < m + n; i++)
	ans[i] = 0;
for (i = 0; i < m + n; i++) {
	scanf_s("%d", &p3[i]);
}

merge(p3, ans, 0, m, n);

return 0;
*/