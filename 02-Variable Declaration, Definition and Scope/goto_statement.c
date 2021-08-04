// C program to check if a number is
// even or not using goto statement
#include <stdio.h>
// function to check even or not
void
checkEvenOrNot(int num) {
	if (num % 2 == 0)
		// jump to even
		goto even;
	else
		// jump to odd
		goto odd;
even:
	printf("%d is even.\n", num);
	// return if even
	return;
odd:
	printf("%d is odd.\n", num);
}

// function to print numbers from 1 to 10.
void
printNumbers() {
    int n = 1;
label:
    printf("%d, ", n);
    n++;
    if (n <= 10)
        goto label;
    printf("\b\b \n");
}

int
main() {
	int num = 26;
	checkEvenOrNot(num);
    printNumbers();

	return 0;
}
