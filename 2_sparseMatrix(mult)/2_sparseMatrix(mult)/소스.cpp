//미완
#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x, y) ( (x) < (y) ? (-1) : ((x) == (y)) ? (0) : (1) )
#define MAX_COL 50
#define MAX_TERMS 50

struct term {
	int row;
	int col;
	int value;
};

void fast_transpose(term a[], term b[]) {

	int row_terms[MAX_COL]; //a의 열의 원소 수 저장
	int i, j, num_col = a[0].col, num_terms = a[0].value;

	b[0].row = a[0].col; b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (num_terms > 0) {

		for (i = 0; i < MAX_COL; i++)
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

void storesum(term d[], int* totald, int row, int column, int* sum) {

	//static int num = 0;
	//printf("%d\n", ++num);
	//printf("%d\n", *sum);

	if (*sum) {
		if (*totald < MAX_TERMS) {
			d[++*totald].row = row;
			d[*totald].col = column;
			d[*totald].value = *sum;
			*sum = 0;
		}
		else {
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			exit(1);
		}
	}

}

void mmult(term a[], term b[], term d[]) {

	int i, j, column, totald = 0;
	int totala = a[0].value, totalb = b[0].value;
	int row_begin = 1, row = a[1].row, sum = 0;
	term new_b[MAX_TERMS];

	if (a[0].col != b[0].row) { //행렬곱의조건
		fprintf(stderr, " Incompatible matrices\n");
		exit(1);
	}
	fast_transpose(b, new_b);

	/*printf("\n");
	for (int i = 0; i < new_b[0].value + 1; i++)
		printf("%d %d %d\n", new_b[i].row, new_b[i].col, new_b[i].value);
	printf("\n");*/

	// 경계 조건을 설정
	a[totala + 1].row = a[0].row;
	new_b[totalb + 1].row = b[0].col;
	//new_b[totalb + 1].col = 0;//??

	for (i = 1; i <= totala; ) {

		column = new_b[1].row;
		//if (i > totala) break;
		//printf("test\n");
		for (j = 1; j <= totalb + 1;) {
			
			if (a[i].row != row) {
				storesum(d, &totald, row, column, &sum);
				i = row_begin;
				for (; new_b[j].row == column; j++);
				column = new_b[j].row;
			}
			else if (new_b[j].row != column) {
				storesum(d, &totald, row, column, &sum);
				i = row_begin;
				column = new_b[j].row;
			}
			else {
				switch (COMPARE(a[i].col, new_b[j].col)) {
				case -1:
					i++; break;
				case 0:
					sum += (a[i++].value * new_b[j++].value); break;
				case 1:
					j++;
				}
			}
			for (; a[i].row == row; i++)

			row_begin = i; row = a[i].row;
			printf("row_begin = %d, row = %d\n", row_begin, row);
			//printf("i = %d, j = %d\n", i, j);
		}
		
	}
	d[0].row = a[0].row;
	d[0].col = b[0].col; d[0].value = totald;

}
int main() {

	term a[9], b[6], d[MAX_TERMS];

	for (int i = 0; i < 9; i++)
		scanf_s("%d%d%d", &a[i].row, &a[i].col, &a[i].value);
	for (int i = 0; i < 6; i++)
		scanf_s("%d%d%d", &b[i].row, &b[i].col, &b[i].value);

	mmult(a, b, d);

	printf("\n");
	for (int i = 0; i < d[0].value; i++)
		printf("%d %d %d\n", d[i].row, d[i].col, d[i].value);
	
	return 0;
}