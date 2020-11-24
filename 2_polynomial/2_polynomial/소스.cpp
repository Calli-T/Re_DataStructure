#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x, y) ((x) < (y) ? (-1) : ((x) == (y)) ? (0) : (1) ))
#define MAX_TERMS 100

int avail;
struct poly {
	float coef;
	int expon;
};
poly terms[100];

void attach(float coefficient, int exponent) {

	if(avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial \n.");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;

}

void padd(int starta, int finisha, int startb, int finishb, int* startd, int* finishd) {
	
	float coefficient;
	*startd = avail;

	while (starta <= finisha && startb <= finishb) {
		switch (COMPARE(terms[starta].expon, terms[startb].expon) {

		case -1:
			attach(terms[startb].coef, terms[startb].expon);
			//printf("%d\n", terms[startb].expon);
			startb++; break;
			
		case 0:
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient) attach(coefficient, terms[starta].expon);
			starta++; startb++;
			break;
		case 1:
			attach(terms[starta].coef, terms[starta].expon);

			starta++;
		}
	}
		for (; starta <= finisha; starta++)
			attach(terms[starta].coef, terms[starta].expon);

		for (; startb <= finishb; startb++)
			attach(terms[startb].coef, terms[startb].expon);

		*finishd = avail - 1;
	
}

int main() {

	int a, b;
	scanf_s("%d%d", &a, &b);
	int sd = 0, fd = 0;
	int* startd = &sd;
	int* finishd = &fd;

	int i;
	for (i = 0; i < a; i++) {
		scanf_s("%f%d", &terms[avail].coef, &terms[avail].expon);
		avail++;
	}
	for (i = 0; i < b; i++) {
		scanf_s("%f%d", &terms[avail].coef, &terms[avail].expon);
		avail++;
	}

	padd(0, a - 1, a, a + b - 1, startd, finishd);

	for (i = *startd; i < *finishd; i++)
		printf("%.0f^%d + ", terms[i].coef, terms[i].expon);
	printf("%.0f^%d", terms[i].coef, terms[i].expon);

	return 0;

}