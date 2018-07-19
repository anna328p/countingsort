#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int max(int* arr, size_t len) {
	if (len < 1) {
		return 0;
	}
	int greatest = arr[0];
	for (size_t i = 0; i < len; i++)
		if (arr[i] > greatest)
			greatest = arr[i];
	return greatest;
}

void sort(int* inputs, int* outputs, size_t length) {
	// this is the size of the array of counts
	int greatest = max(inputs, length);	// find the greatest number in the array

	// allocate the array of counts
	int* counts = calloc(greatest + 1, sizeof(int));
	if (counts == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	// count numbers in input array
	for (size_t i = 0; i < length; i++) {
		counts[inputs[i]]++;
	}

	size_t counter = 0;	// keep track of where we are in output array

	// loop through all the counts
	for (int i = 0; i <= greatest; i++) {	// for every count in array
		for (int j = 0; j < counts[i]; j++) {	// loop that many times
			outputs[counter++] = i;	// add the integer being counted to the output array
		}
	}
	free(counts);
}

int main(int argc, char** argv) {
	int *inputs, *outputs;
	size_t length = argc - 1;	// number of integers to sort

	if (argc < 2) {
		fprintf(stderr, "Not enough arguments given.\n");
		exit(EXIT_FAILURE);
	}

	inputs = calloc(length, sizeof(int));
	outputs = calloc(length, sizeof(int));

	if (inputs == NULL || outputs == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++) {
		inputs[i - 1] = atoi(argv[i]);	// assign arguments to array
	}

	sort(inputs, outputs, length);

	for (size_t i = 0; i < length; i++) {
		printf("%d ", outputs[i]);	// print space separated sorted numbers
	}
	printf("\n");

	free(inputs);
	free(outputs);

	return EXIT_SUCCESS;
}
