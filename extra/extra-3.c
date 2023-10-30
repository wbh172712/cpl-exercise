//
// Created by wbh17 on 2023/10/24.
//
#include <stdio.h>

// Function to print the Sudoku grid
void printSudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d", grid[row][col]);
            if (col < 8) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a number in a specific cell
int isSafe(int grid[9][9], int row, int col, int num) {
    // Check if 'num' is not in the current row or column
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    // Check if 'num' is not in the current 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku using backtracking
int solveSudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku(grid)) {
                            return 1; // Successfully solved
                        }

                        grid[row][col] = 0; // Backtrack
                    }
                }
                return 0; // No solution for this cell
            }
        }
    }
    return 1; // Sudoku solved
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int grid[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        if (solveSudoku(grid)) {
            printSudoku(grid);
        } else {
            printf("No solution found.\n");
        }

        if (t < T - 1) {
            printf("\n"); // Separate test cases with a blank line
        }
    }

    return 0;
}

