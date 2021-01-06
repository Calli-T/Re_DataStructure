#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100

int parent[MAX_ELEMENTS];

int simpleFind(int i) {
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}
void simpleUnion(int i, int j) {
	parent[i] = j;
}

void weightedUnion(int i, int j) {
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) {
		parent[i] = j;
		parent[j] = temp;
	}
	else {
		parent[j] = i;
		parent[i] = temp;
	}
}

int collapsingFind(int i) {
	int root, trail, lead;
	for (root = i; parent[root] >= 0; root = parent[root]);
	for (trail = i; trail != root; trail = lead) {
		lead = parent[trail];
		parent[trail] = root;
	}
	return root;
}

int main(void) {

	int arr[10] = { -1,4,-1,2,-1,2,0,0,0,4 };
	for (int i = 0; i < 10; i++)
		parent[i] = arr[i];

	int a = simpleFind(8);
	printf("8은 root가 %d인 집합의 원소\n", a);
	simpleUnion(0, 4);
	a = simpleFind(8);
	printf("8은 root가 %d인 집합의 원소\n", a);
	simpleUnion(4, 2);
	a = simpleFind(8);
	printf("8은 root가 %d인 집합의 원소\n", a);

	arr[0] = -3;
	arr[4] = -2;
	arr[2] = -2;
	for (int i = 0; i < 10; i++)
		parent[i] = arr[i];

	//a = simpleFind(9);
	//printf("9은 root가 %d인 집합의 원소\n", a);
	weightedUnion(2, 4);
	a = simpleFind(9);
	printf("9은 root가 %d인 집합의 원소\n", a);
	weightedUnion(2, 0);
	a = simpleFind(9);
	printf("9은 root가 %d인 집합의 원소\n", a);

	/*for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int b = collapsingFind(6);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("6은 root가 %d인 집합의 원소\n", b);*/

	printf("\n");

	for (int i = 0; i < 10; i++)
		parent[i] = -1;
	weightedUnion(0, 1);
	weightedUnion(2, 3);
	weightedUnion(4, 5);
	weightedUnion(6, 7);
	weightedUnion(0, 2);
	weightedUnion(4, 6);
	weightedUnion(0, 4);

	/*printf("7의 부모는%d\n", parent[7]);
	int b = collapsingFind(7);
	printf("7의 부모는%d\n", parent[7]);*/

	int c = 8;
	while (c--) {
		collapsingFind(7);
	}//3번의 이동과 3번의 재설정(7,6,4) 그리고 나머지 7번의 이동 총 13번 작동

	return 0;
}