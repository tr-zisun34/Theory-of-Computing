#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

int numberOfStates, numOfAlpha, countOfTransition[MAX][MAX], pathLength = 0;
char states[MAX], alphabet[MAX], transition[MAX][MAX][MAX], str[MAX], start, final, path[MAX], current_state;

bool traverse(int ptr, char curr) {
    bool result = false;

    if (ptr == strlen(str)) {
        return curr == final;
    }

    for (int j = 0; j < numOfAlpha; j++) {
        if (str[ptr] == alphabet[j]) {
            for (int k = 0; k < countOfTransition[abs(curr - states[0])][j]; k++) {
                char nextState = transition[abs(curr - states[0])][j][k];
                result = result || traverse(ptr + 1, nextState);
                if (result == true) {
                    path[pathLength++] = nextState;
                }
            }
        }
    }
    return result;
}

int main() {
    printf("Enter number of states: ");
    scanf("%d", &numberOfStates);
    printf("Enter states:\n");
    for (int i = 0; i < numberOfStates; i++) {
        scanf(" %c", &states[i]);
    }

    printf("Enter number of alphabet: ");
    scanf("%d", &numOfAlpha);
    printf("Enter alphabets:\n");
    for (int i = 0; i < numOfAlpha; i++) {
        scanf(" %c", &alphabet[i]);
    }

    for (int i = 0; i < numberOfStates; i++) {
        for (int j = 0; j < numOfAlpha; j++) {
            printf("From State: %c via \"%c\" to State:\n", states[i], alphabet[j]);
            printf("How many transitions: ");
            scanf("%d", &countOfTransition[i][j]);
            for (int k = 0; k < countOfTransition[i][j]; k++) {
                scanf(" %c", &transition[i][j][k]);
            }
        }
    }

    printf("Enter string: ");
    scanf("%s", str);

    printf("Enter starting state:");
    scanf(" %c", &start);

    printf("Enter final state: ");
    scanf(" %c", &final);

    current_state = start;
    printf("path: ");
    if (traverse(0, start)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    path[pathLength++] = start;
    int n = pathLength;
    printf("path: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c -> ", path[i]);
    }
    printf("\n\n");
    return 0;
}
