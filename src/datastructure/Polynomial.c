#define MAX_TERMS 101

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

typedef struct {
	float coef;
	int expon;
} poly;

poly terms[MAX_TERMS] = { { 2, 1000 }, { 1, 0 }, { 1, 4 }, { 10, 3 }, { 3, 2 },
		{ 1, 0 } };

int avail = 6;

void attach(float coefficient, int exponent) {
	if (avail >= MAX_TERMS) {
		return;
	}

	terms[avail].coef = coefficient;
	terms[avail].expon = exponent;
	avail++;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd,
		int *finishd) {
	float coefficient;
	*startd = avail;

	while (starta <= finisha && startb <= finishb) {
		switch (COMPARE(terms[starta].expon, terms[startb].expon)) {
		case -1:
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case 0:
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient) {
				attach(coefficient, terms[starta].expon);
			}
			starta++;
			startb++;
			break;
		case 1:
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
			break;
		}
	}

	for (; starta <= finisha; starta++) {
		attach(terms[starta].coef, terms[starta].expon);
	}

	for (; startb <= finishb; startb++) {
		attach(terms[startb].coef, terms[startb].expon);
	}

	*finishd = avail - 1;
}
