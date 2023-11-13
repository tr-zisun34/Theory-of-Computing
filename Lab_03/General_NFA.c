#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 1000
#define MAX_ALPHABET 100

int numStates, numAlphabet, transitionCount[MAX_STATES][MAX_ALPHABET], pathLength = 0;
char states[MAX_STATES], alphabet[MAX_ALPHABET], transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES], inputString[MAX_STATES], startState, finalState, path[MAX_STATES], currentState;

bool traverse(int ptr, char curr)
{
    bool result = false;

    if (ptr == strlen(inputString))
    {
        return curr == finalState;
    }

    for (int j = 0; j < numAlphabet; j++)
    {
        if (inputString[ptr] == alphabet[j])
        {
            for (int k = 0; k < transitionCount[abs(curr - states[0])][j]; k++)
            {
                char nextState = transitions[abs(curr - states[0])][j][k];
                result = result || traverse(ptr + 1, nextState);
                if (result == true)
                {
                    path[pathLength++] = nextState;
                }
            }
        }
    }
    return result;
}

int main()
{
    printf("Enter number of states: ");
    scanf("%d", &numStates);
    printf("Enter states:\n");
    for (int i = 0; i < numStates; i++)
    {
        scanf(" %c", &states[i]);
    }

    printf("Enter number of alphabet: ");
    scanf("%d", &numAlphabet);
    printf("Enter alphabets:\n");
    for (int i = 0; i < numAlphabet; i++)
    {
        scanf(" %c", &alphabet[i]);
    }

    for (int i = 0; i < numStates; i++)
    {
        for (int j = 0; j < numAlphabet; j++)
        {
            printf("From State: %c via \"%c\" to State:\n", states[i], alphabet[j]);
            printf("How many transitions: ");
            scanf("%d", &transitionCount[i][j]);
            for (int k = 0; k < transitionCount[i][j]; k++)
            {
                scanf(" %c", &transitions[i][j][k]);
            }
        }
    }

    printf("Enter string: ");
    scanf("%s", inputString);

    printf("Enter starting state:");
    scanf(" %c", &startState);

    printf("Enter final state: ");
    scanf(" %c", &finalState);

    currentState = startState;
    printf("Path: ");
    if (traverse(0, startState))
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    path[pathLength++] = startState;
    int n = pathLength;
    printf("Path: ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%c -> ", path[i]);
    }
    printf("\n\n");
    return 0;
}
