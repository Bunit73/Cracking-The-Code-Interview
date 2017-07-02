#include <stdio.h>
#include <stdlib.h>

int checkIfAllUniqueBrute(char*, int);
int checkIfAllUniqueBetter(char*, int);

int main(int argc, char *argv[]) {
	char *strArr = "ABC";
	int len = sizeof(strArr) / sizeof(strArr[0]);
	
	if (checkIfAllUniqueBrute(strArr, len)) {
		printf("%s\n", "Brute Force: All Chars are Unique");
	}
	else {
		printf("%s\n", "Brute Force: Duplicate Values Exist");
	}

	if (checkIfAllUniqueBetter(strArr, len)) {
		printf("%s\n", "Better : All Chars are Unique");
	}
	else {
		printf("%s\n", "Better: Duplicate Values Exist");
	}

	return 0;
}


/*
Check if all chars in a string are unique, brute force method
input:    char* array, len of the array
output:   Bool, 1 = TRUE, 0 = FALSE
*/
int checkIfAllUniqueBrute(char* arr, int len) {
	int i,j;
	for (i = 0; i < len; i++) {
		for (j = i+1; j < len; j++) {
			if (arr[i] == arr[j]) {
				return 0;
			}
		}
	}
	return 1;
};


int checkIfAllUniqueBetter(char* arr, int len) {
	int i, pos;
	int usedArr[128] = { 0 };

	for (i = 0; i < len; i++) {
		pos = (int)arr[i];
		//letter was used before
		if (usedArr[pos] == 1) {
			return 0;
		}
		else {
			usedArr[pos] = 1;
		}
	}
	return 1;
}