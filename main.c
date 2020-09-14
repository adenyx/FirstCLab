#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int first () {
    int n = 5;
    int array[n][n];
    int maxElement = 0;
    printf("The number of lines and columns: \n");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7d", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int i = 0, j = 0;
    int maxRow = 0, maxCol = 0;
    while (i < n) {
        if (array[i][j] >= maxElement) {
            maxElement = array[i][j];
            maxRow = i;
            maxCol = j;
        }
        i++;
        j++;
    }
    i = n-1, j = 0;
    while (i >= 0) {
        if (array[i][j] >= maxElement) {
            maxElement = array[i][j];
            maxRow = i;
            maxCol = j;
        }
        i--;
        j++;
    }
    printf("%d\n\n", maxElement);

    int variable = array[n / 2][n / 2];
    array[n / 2][n / 2] = maxElement;
    array[maxRow][maxCol] = variable;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7d", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}

int second() {
    int n = 3;
    int A[3][3] = {
            { 3, -2,  4},
            {-2, -6, -4},
            { 1,  5, -9}
    };
    int array[3][3] = {
            { 3, -2,  4},
            {-2, -6, -4},
            { 1,  5, -9}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int maxNegative[n], maxPositive[n];
    //find maxNegative in row
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] < 0) {
                score += 1;
            }
        }
        maxNegative[i] = score;
        score = 0;
    }

    int maxNegativeRow = 0;
    for (int i = 0; i < n; i++) {
        if (maxNegative[i] > maxNegativeRow) {
            maxNegativeRow = i;
        }
    }

    for (int i = 0; i < n; i++) {
        array[maxNegativeRow][i] = 0;
    }

    //find maxPositive in column
    int scoreCol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j][i] > 0) {
                scoreCol += 1;
            }
        }
        maxPositive[i] = scoreCol;
        scoreCol = 0;
    }

    int maxPositiveCol = 0;
    for (int i = 0; i < n; i++) {
        if (maxPositive[i] > maxPositiveCol) {
            maxPositiveCol = i-2;
        }
    }

    for (int i = 0; i < n; i++) {
        array[i][maxPositiveCol] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7d", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int choose = 0;
    printf("1 / 2: ");
    scanf("%d", &choose);
    if (choose == 1) {
        first();
    } else if (choose == 2) {
        second();
    } else {
        printf("Input Error");
    }
    return 0;
}

