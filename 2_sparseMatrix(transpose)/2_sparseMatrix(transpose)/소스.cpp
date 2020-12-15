#include <stdio.h>
#include <stdlib.h>

struct term {
	int row;
	int col;
	int value;
};

void transpose(term a[], term b[]) {
	int count, i, j, currentb;

	count = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = count;

	if (count > 0) { 
		currentb = 1;
		
		for (i = 0; i < a[0].col; i++) {
			
			for (j = 1; j <= count; j++) {

				if (a[j].col == i) {
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}

			}

		}

	}
}

int main() {

	term a[9], b[9];
	
	for (int i = 0; i < 9; i++)
		scanf_s("%d%d%d", &a[i].row, &a[i].col, &a[i].value);

	transpose(a, b);

	printf("\n");
	for (int i = 0; i < 9; i++)
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	

	return 0;
}