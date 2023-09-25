//
// Created by wbh17 on 2023/9/15.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die and return the result
int rollDie() {
    return (rand() % 6) + 1;
}

// Function to calculate the absolute difference between two digits
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to calculate the score for rolling zero dice (Free Bacon rule)
int calculateFreeBacon(int opponentScore) {
    int digit1 = opponentScore / 10;
    int digit2 = opponentScore % 10;
    return 2 + absDiff(digit1, digit2);
}

// Function to check if two scores can be swapped (Swine Swap rule)
int canSwineSwap(int playerScore, int opponentScore) {
    if (playerScore <= 1 || opponentScore <= 1)
        return 0;

    if ((playerScore % opponentScore == 0) || (opponentScore % playerScore == 0))
        return 1;

    return 0;
}

// Function to play a turn
int playTurn(int currentPlayerScore, int opponentScore) {
    int rollCount; // Get the number of dice to roll from the user
    printf("Enter the number of dice to roll (1-10): ");
    scanf("%d", &rollCount);

    // Roll the dice and calculate the score for the turn
    int turnScore = 0;
    for (int i = 0; i < rollCount; i++) {
        int roll = rollDie();
        printf("Die %d: %d\n", i + 1, roll);
        if (roll == 1) {
            turnScore = 1; // Pig Out
            break;
        }
        turnScore += roll;
    }

    if (rollCount == 0) {
        turnScore = calculateFreeBacon(opponentScore);
        printf("Free Bacon: %d points\n", turnScore);
    }

    int newPlayerScore = currentPlayerScore + turnScore;

    // Check for Swine Swap
    if (canSwineSwap(newPlayerScore, opponentScore)) {
        int temp = newPlayerScore;
        newPlayerScore = opponentScore;
        opponentScore = temp;
    }

    return newPlayerScore;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int player1Score = 0;
    int player2Score = 0;
    int currentPlayer = 1;

    printf("Welcome to Hog!\n");

    while (player1Score < 100 && player2Score < 100) {
        printf("\nPlayer %d's turn:\n", currentPlayer);
        if (currentPlayer == 1) {
            player1Score = playTurn(player1Score, player2Score);
        } else {
            player2Score = playTurn(player2Score, player1Score);
        }

        printf("Player 1: %d points\n", player1Score);
        printf("Player 2: %d points\n", player2Score);

        // Switch to the other player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    // Determine the winner
    if (player1Score >= 100) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}