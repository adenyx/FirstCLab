#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 7
#define _CRT_SECURE_NO_WARNINGS

//Дана действительная квадратная матрица порядка n, все элементы которой различны.
//Найти наибольший элемент среди стоящих на главной и побочной диагоналях и поменять его местами с элементом,
//стоящим на пересечении этих диагоналей.
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

//В матрице А обнулить строку с максимальным числом отрицательных элементов
//и столбец с максимальным числом положительных элементов.
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

//Если наибольший элемент матрицы А лежит выше главной диагонали,
//найти сумму элементов матрицы, лежащих выше главной диагонали.
//Иначе найти сумму элементов, лежащих ниже и на главной диагонали
int third() {
    int n = 5, a[n][n];
    int maxElement = 0, maxElementI, maxElementJ;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
        }
    }

    //output matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7d", a[i][j]);
        }
        printf("\n");
    }

    //find max element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > maxElement) {
                maxElement = a[i][j];
                maxElementI = i;
                maxElementJ = j;
            }
        }
    }

    //check the position of the max element
    if (maxElementJ > maxElementI) {
        //TODO Add functionality for finding the sum of matrix elements:
        // above the main diagonal
    } else {
        //TODO Add functionality for finding the sum of matrix elements:
        // below the main diagonal and on this diagonal
    }

}

//Дана действительная квадратная матрица порядка n. Найти наименьшее
//из значений элементов, расположенных в заштрихованной части матрицы.
//(сверху, снизу и слева между диагоналями)((сами диагонали не учитываем))
int fourth() {
    int array[N][N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            array[i][j] = rand() % 100;
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    int min = array[0][1];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (j > i && j < N - i - 1) {
                if (array[i][j] < min) {
                    min = array[i][j];
                }
                int k = N - i -1;
                if (array[k][j] < min) {
                    min = array[k][j];
                }
            }
    printf("\n");
    printf("First minimal element: %d", min);

    int min_1 = array[1][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i > j && i < N - j - 1) {
                if (array[i][j] < min_1) {
                    min_1 = array[i][j];
                }
            }
    printf("\n");
    printf("Second minimal element: %d", min_1);
    printf("\n");
    system("pause");
}

//some condition :3
int fifth() {
    int array[5][5];
}

int main() {
    int choose = 0;
    printf("1 / 2 / 3 / 4: ");
    scanf("%d", &choose);
    if (choose == 1) {
        first();
    } else if (choose == 2) {
        second();
    } else if (choose == 3) {
        third();
    } else if (choose == 4) {
        fourth();
    } else {
        printf("Input Error");
    }
    return 0;
}

