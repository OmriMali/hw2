#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// SECTION A: Recursive Subsequences Generation
void generate_subsequences(char* str, char* current, int index) {
	// TODO: Implement the recursive logic for generating subsequences
	char new_current[100];
	int lengh_str = strlen(current);
	if (index == strlen(str)) {
		current[index] = '\0';
		printf("%s\n", current);
		return;
	}
	strcpy(new_current, current);
	current[lengh_str] = str[index];
	current[lengh_str + 1] = '\0';
	generate_subsequences(str, current, index + 1);
	generate_subsequences(str, new_current, index + 1);
}
		

// Driver Program
int main() {
	char str[100];
	char current[100] = "";

	printf("Enter a string: ");
	scanf("%s", str);

	printf("Subsequences:\n");
	generate_subsequences(str, current, 0);

	return 0;
}
