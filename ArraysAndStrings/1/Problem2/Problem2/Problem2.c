//Problem 2 see if a string is a permuation of the other
#include <stdio.h>
#include <stdlib.h>

int testPermBrute(char *, char *);
int betterPerm(char *, char *);
void merge(char *, int, int);
void mergeSort(char, int, int);

int main(int argc, char *argv[]) {
	char *str1 = "abc";
	char *str2 = "dac";

	if (testPermBrute(str1, str2)) {
		printf("%s\n", "Brute Force A is a Perm of B");
	}
	else {
		printf("%s\n", "Brute Force A is NOT Perm of B");
	}

	//betterPerm(str1, str2);
	if (betterPerm(str1, str2)) {
		printf("%s\n", "Sort Algo: A is a Perm of B");
	}
	else {
		printf("%s\n", "Sort Algo: A is NOT Perm of B");
	}

	return 0;
}

int testPermBrute(char * strA, char * strB){
	int sizeA, sizeB, i, j, test;
	sizeA = sizeof(strA) / sizeof(strA[0]);
	sizeB = sizeof(strB) / sizeof(strB[0]);

	if (sizeA != sizeB) {
		fprintf(stderr, "%s\n", "Strings are not equal size");
		return 0;
	}

	for (i = 0; i < sizeA; i++) {
		test = 0;
		for (j = 0; j < sizeB; j++) {
			if (strA[i] == strB[j]) {
				test = 1;
			}
		}
		if (test != 1) {
			//A isnt in B
			return 0;
		}
	}

	return 1;
}

int betterPerm(char * strA, char * strB){
	int sizeA, sizeB, i;
	sizeA = sizeof(strA) / sizeof(strA[0]);
	sizeB = sizeof(strB) / sizeof(strB[0]);

	if (sizeA != sizeB) {
		fprintf(stderr, "%s\n", "Strings are not equal size");
		return 0;
	}


	//We dont care about the null term
	//TODO: merege sort is wonking out with char*
	mergeSort(strA, 0, sizeA - 2);
	mergeSort(strB, 0, sizeB - 2);


	for (i = 0; i < sizeA; i++) {
		if (strA[i] != strB[i]) {
			return 0;
		}
	}

	return 1;
}

//For merege sort
void merge(char *arr, int l, int m, int r) {
	int i, j, k;
	//middle - left
	const int n1 = m - l + 1;
	//right - middle
	const int n2 = r - m;

	//Create the temp arrays
	char *L = malloc(sizeof(char) * n1);
	char *R = malloc(sizeof(char) * n2);

	//Copy data into temp arrays
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}

	//Merge the arrays back together
	i = 0; //idx of first sub arr
	j = 0; //idx of second sub arr
	k = l; //idx of mereged sub arr
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	//Copy the remaining elements of L if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	//Copy the remaining elements of R over
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void mergeSort(char *arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		//sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}