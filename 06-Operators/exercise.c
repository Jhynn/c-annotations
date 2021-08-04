#include <stdio.h>
#include <stdbool.h>
// Given a set of numbers where all elements occur even number of times 
// except one number, find the odd occurring number.

int
findOdd(int arr[], int n) {
	int res = 0;

	for (register int i = 0; i < n; i++)
		res ^= arr[i]; // XOR
	return res;
}

void
format_name(char* name, int size) {
	int delimiter;
	for (register int i = 0; i < size; i++) {
		if (name[i] == ' ')
			delimiter = i; // Find the last ' '.
	}

	int aux = ++delimiter;
	while (name[aux] != '\0') {
		printf("%c", name[aux]); // print the sobrenome.
		++aux;
	}
	printf(", ");

	aux = -1;
	while (++aux != delimiter) {
		printf("%c", name[aux]); // print the rest of the name.
	}
	puts("");
}

int
main(void) {
	int array[] = {12, 12, 14, 90, 14, 14, 14};
	int proper_size = sizeof(array) / sizeof(array[0]);

	char example[] = "Nome Prefixo Nome_do_meio Sufixo Sobrenome";

	printf("The odd occurring element is %d\n",
			findOdd(array, proper_size));

	int size = (int) sizeof(example);
	format_name(example, size);

	return 0;
}
