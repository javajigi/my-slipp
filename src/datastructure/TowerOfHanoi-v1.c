void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void move(int* sourceTower, int sourceLength, int* secondTower,
		int secondLength, int* targetTower, int targetLength) {
	swap(sourceTower + sourceLength - 1, secondTower + secondLength);
	swap(sourceTower + sourceLength - 2, targetTower + targetLength);
	swap(secondTower + secondLength, targetTower + targetLength + 1);
}

void moveThree(int* sourceTower, int sourceLength, int* secondTower,
		int secondLength, int* thirdTower, int targetLength) {
	move(sourceTower, sourceLength, secondTower, 0, thirdTower, 0);
	swap(sourceTower + (sourceLength-3), secondTower);
	move(thirdTower, sourceLength - 1, secondTower, 1, sourceTower, 0);
	swap(secondTower, thirdTower);
	move(sourceTower, sourceLength - 1, secondTower, 0, thirdTower, 1);
}

void hanoi(int *firstTower, int *secondTower, int *thirdTower, int firstLength) {
	if (firstLength == 2) {
		swap(firstTower + 1, secondTower);
		swap(firstTower, thirdTower);
		swap(secondTower, thirdTower + 1);
	} else if (firstLength == 3) {
		swap(firstTower + 2, thirdTower);
		swap(firstTower + 1, secondTower);
		swap(thirdTower, secondTower + 1);

		swap(firstTower, thirdTower);

		swap(secondTower + 1, firstTower);
		swap(secondTower, thirdTower + 1);
		swap(firstTower, thirdTower + 2);
	} else if (firstLength == 4) {
		move(firstTower, firstLength, secondTower, 0, thirdTower, 0);
		swap(firstTower + 1, secondTower);
		move(thirdTower, 2, secondTower, 1, firstTower, 1);
		swap(secondTower, thirdTower);
		move(firstTower, firstLength-1, secondTower, 0, thirdTower, 1);

		swap(secondTower, firstTower);
		move(thirdTower, firstLength-1, secondTower, 1, firstTower, 0);
		swap(thirdTower, secondTower+1);
		move(firstTower, firstLength-2, secondTower, 2, thirdTower, 0);
		swap(secondTower+1, firstTower);
		move(thirdTower, firstLength-2, secondTower, 1, firstTower, 1);
		swap(secondTower, thirdTower);

		move(firstTower, firstLength-1, secondTower, 0, thirdTower, 1);
		swap(firstTower, secondTower);
		move(thirdTower, firstLength-1, secondTower, 1, firstTower, 0);
		swap(secondTower, thirdTower+1);
		move(firstTower, firstLength-2, secondTower, 0, thirdTower, firstLength-2);
	}
}
