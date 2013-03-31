void printStar(int i) {
	int starLength = 2 * i + 1;
	for (int j = 0; j < starLength; j++) {
		printf("*");
	}
}

void printSpace(int start, int end) {
	for (int j = start; j < end - 1; j++) {
		printf(" ");
	}
}

void printLine(int i, int mid, int length) {
	printSpace(i, mid);
	printStar(i);
	printSpace(mid+i , length);
	printf(" \n");
}

void diamond(int length) {
	int mid = (length + 1) / 2;
	for (int i = 0; i < mid; i++) {
		printLine(i, mid, length);
	}

	for (int i = mid+1; i <= length; i++) {
		printLine(length-i, mid, length);
	}
}
