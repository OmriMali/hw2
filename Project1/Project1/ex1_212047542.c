#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// SECTION A: Recursive Palindrome Check
int is_palindrome_recursive(char* str, int start, int end) {
	while (!((str[start] >= 65 && str[start] <= 90) || (str[start] >= 97 && str[start] <= 122) || (str[start] >= 48 && str[start] <= 57)) && start<=end)
		start++;
	while (!((str[end] >= 65 && str[end] <= 90) || (str[end] >= 97 && str[end] <= 122) || (str[start] >= 48 && str[start] <= 57)) && start<=end)
		end--;
	if (start == end)
		return 1;
	if (start == (end - 1))
		return (tolower(str[start])== tolower(str[end]));
	if (tolower(str[start]) != tolower(str[end]))
		return 0;
	else
		return is_palindrome_recursive(str, ++start, --end);
	return 0; // Placeholder return value
}

// SECTION B: Iterative Palindrome Check
int is_palindrome_iterative(char* str) {
	int start = 0, end=strlen(str)-1;
	while (start <= end) {
		while (!((str[start] >= 65 && str[start] <= 90) || (str[start] >= 97 && str[start] <= 122) || (str[start] >= 48 && str[start] <= 57)) && start <= end)
			start++;
		while (!((str[end] >= 65 && str[end] <= 90) || (str[end] >= 97 && str[end] <= 122) || (str[start] >= 48 && str[start] <= 57)) && start <= end)
			end--;
		if (start == end)
			return 1;
		if (start == (end - 1))
			return (tolower(str[start]) == tolower(str[end]));
		if (tolower(str[start]) != tolower(str[end]))
			return 0;
		else {
			start++;
			end--;
		}
	}
	if (start >= end)
		return 1;
	return 0; // Placeholder return value
}

// Driver Program
int main() {
	char str[1000];

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);

	// Remove newline character
	str[strcspn(str, "\n")] = '\0';

	printf("\nResults:\n");
	printf("Recursive Palindrome Check: %s\n", is_palindrome_recursive(str, 0, strlen(str) - 1) ? "Palindrome" : "Not a Palindrome");
	printf("Iterative Palindrome Check: %s\n", is_palindrome_iterative(str) ? "Palindrome" : "Not a Palindrome");

	return 0;
}
