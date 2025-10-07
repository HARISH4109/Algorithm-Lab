#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];


void printSolution(int n) {
    int i, j;
    static int count = 1;
    printf("\nSolution %d:\n", count++);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}


int isSafe(int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

int solutionFound = 0;


void solveNQueens(int row, int n) {
    int col;
    if (row == n) {
        printSolution(n);
        return;
    }
    for (col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Please enter N between 1 and %d\n", MAX);
        return 1;
    }

    solveNQueens(0, n);

    if (!solutionFound)
        printf("No solution exists for %d-Queens problem.\n", n);

    return 0;
}
