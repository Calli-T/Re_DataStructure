#include <stdio.h>
#define SWAP(x, y, z) ((z)=(x), (x)=(y), (y) = (z))

void perm(char* list, int i, int n);

int main() {

	char list[] = { 'a', 'b', 'c', 'd' };

	perm(list, 0, 3);

	return 0;
}

//list 배열의 i부터 n까지의 원소의 순열을 보여라
void perm(char* list, int i, int n) {
	int j, temp;
	if (i == n) {
		for (j = 0; j <= n; j++)
			printf("%c", list[j]);
		printf("\n");
	}
	else {
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}

}