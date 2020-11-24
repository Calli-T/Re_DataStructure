#include <stdio.h>

#define MAX_COL 50
struct term {
	int row;
	int col;
	int value;
};

void fast_transpose(term a[], term b[]) {

	int row_terms[MAX_COL]; //a의 열의 원소 수 저장
	int starting_pos[MAX_COL]; //각 열의 시작위치 저장
	int i, j, num_col = a[0].col, num_terms = a[0].value;

	b[0].row = a[0].col; b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (num_terms > 0) {

		for (i = 0; i < num_col; i++)
			row_terms[i] = 0;

		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;

		starting_pos[0] = 1;
		for (i = 1; i < num_col; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
	
		for (i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;
		}

	}

}

void fast_transpose_inhanced(term a[], term b[]) {

	int row_terms[MAX_COL]; //a의 열의 원소 수 저장
	int i, j, num_col = a[0].col, num_terms = a[0].value;

	b[0].row = a[0].col; b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (num_terms > 0) {

		for (i = 0; i < num_col; i++)
			row_terms[i] = 0;

		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;

		int temp1, temp2;
		temp1 = 1;
		for (i = 0; i < num_col; i++) {
			temp2 = row_terms[i];
			row_terms[i] = temp1;
			temp1 += temp2;
		}

		for (i = 1; i <= num_terms; i++) {
			j = row_terms[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;
		}

	}

}

int main() {

	term a[9], b[9];

	for (int i = 0; i < 9; i++)
		scanf_s("%d%d%d", &a[i].row, &a[i].col, &a[i].value);

	//fast_transpose(a, b);
	fast_transpose_inhanced(a, b);

	printf("\n");
	for (int i = 0; i < 9; i++)
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);

	return 0;
}