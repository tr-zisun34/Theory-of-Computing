#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

int a, m, b, n;
char expression[MAX];
char x[MAX], y[MAX], z[MAX];

int pumping() {
    int k;
    printf("Enter k:");
    scanf("%d", &k);
    int len = strlen(y);
    printf("length of y: %d\n", len);
    char newY[MAX];
    for (int i = 0; i < k * len; i += len) {
        for (int j = 0; j < len; j++) {
            newY[i] = y[j];
        }
    }
    newY[k * len] = '\0';
    printf("%s\n", newY);

    char newExpr[MAX] = "\0";
    strcat(newExpr, x);
    strcat(newExpr, newY);
    strcat(newExpr, z);
    printf("Regular expression after pumping lemma: %s\n", newExpr);

    int newN = 0, newM = 0;
    for (int i = 0; i < strlen(newExpr); i++) {
        if (newExpr[i] == a + '0')
            newN++;
        else
            newM++;
    }

    return ((float)newN / newM) == ((float)n / m);
}

void xyz() {
    int random = rand() % (m - 1);
    printf("random: %d\n", random);
    for (int i = m - 1, j = 0; i > m - 1 - random; i--, j++) {
        y[j] = expression[i];
    }
    y[n] = '\0';
    printf("y: %s\n", y);
    for (int i = 0, j = 0; i <= m - 1 - random; i++, j++) {
        x[j] = expression[i];
    }
    x[n] = '\0';
    printf("x: %s\n", x);
    for (int i = m, j = 0; i < m + n; i++, j++) {
        z[j] = expression[i];
    }
    z[n] = '\0';
    printf("Z: %s\n", z);

    if (pumping())
        printf("Yes, Regular expression\n");
    else
        printf("No, it's not a regular expression\n");
}

int main() {
    printf("Enter a, n, b, m: ");
    scanf("%d%d%d%d", &a, &m, &b, &n);

    for (int i = 0; i < m; i++) {
        expression[i] = (char)(a + '0');
    }
    for (int i = m; i < m + n; i++) {
        expression[i] = (char)(b + '0');
    }

    printf("Expression: %s\n", expression);

    xyz();

    return 0;
}
