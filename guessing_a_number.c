#include <stdio.h>

int main(void) {
	int min = 0;
	int max = 1000;
	int average = (max + min) / 2;
	char answer;
	while  (min < max) {
		average = (max + min) / 2;
		printf("Is your number greater than %d? Type Y or N ", average);
		answer = getchar();
		getchar();
		if (answer == 'Y') {
			min = average + 1;
		}
		if (answer == 'N') {
			max = average;
		}
		if ((answer != 'N') && (answer != 'Y')) {
			printf("Please, type Y or N. Not some other random stuff. ");
		}
	}
	printf("Your number is %d", average);
	return 0;
}