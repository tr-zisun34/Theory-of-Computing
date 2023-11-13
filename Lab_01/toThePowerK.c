#include <stdio.h>
#include <string.h>

// Function to generate and print all strings of length k from alphabet Σ
void generateStrings(char* alphabet, int k, char* currentString, int index) {
    if (index == k) {
        currentString[index] = '\0'; // Null-terminate the string
        printf("%s\n", currentString);
        return;
    }

    for (int i = 0; i < strlen(alphabet); i++) {
        currentString[index] = alphabet[i];
        generateStrings(alphabet, k, currentString, index + 1);
    }
}

int main() {
    char alphabet[] = "01"; // Define your alphabet Σ here
    int k;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k < 0) {
        printf("Invalid input: k must be a non-negative integer.\n");
        return 1;
    }

    if (k == 0) {
        printf("e");
    } else {
        char currentString[k + 1];
        generateStrings(alphabet, k, currentString, 0);
    }

    return 0;
}
