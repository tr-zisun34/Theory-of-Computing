#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkMultiLineComment(const char *line, bool *inMultiLineComment) {
    char *startPos = strstr(line, "/*");
    char *endPos = strstr(line, "*/");

    if (*inMultiLineComment) {
        printf("Line: %s\n", line);
        if (endPos != NULL) {
            printf("Multi-line comment end\n");
            *inMultiLineComment = false;
        } else {
            printf("Mistake! Multi-line comment not end.\n");
        }
        return true;
    } else {
        if (startPos != NULL) {
            if (endPos != NULL) {
                printf("Line: %.*s\n", (int)(endPos - startPos) + 2, startPos);
            } else {
                printf("Line: %s\n", startPos);
                *inMultiLineComment = true;
            }
            return true;
        }
    }

    return false;
}

void processInputFile(const char *filename) {
    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[1000];
    int lineNumber = 0;
    bool inMultiLineComment = false;

    while (fgets(line, sizeof(line), inputFile)) {
        lineNumber++;

        if (!checkMultiLineComment(line, &inMultiLineComment)) {
            char *singleLinePos = strstr(line, "//");
            if (singleLinePos != NULL) {
                printf("Line %d (single-line): %s\n", lineNumber, singleLinePos);
            }
        }
    }

    fclose(inputFile);
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    processInputFile(filename);

    return 0;
}
