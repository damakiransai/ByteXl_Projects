#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int game(char player, char computer) {
    if (player == computer)
        return -1;

    if (player == 'R' && computer == 'P')
        return 0;
    else if (player == 'P' && computer == 'R')
        return 1;

    if (player == 'R' && computer == 'S')
        return 1;
    else if (player == 'S' && computer == 'R')
        return 0;

    if (player == 'P' && computer == 'S')
        return 0;
    else if (player == 'S' && computer == 'P')
        return 1;
}

int main() {
    int n, playerScore = 0, computerScore = 0, result, rounds = 0;
    char player, computer;
    srand(time(NULL));

    while (rounds < 10) {
        n = rand() % 100;
        if (n < 33)
            computer = 'R';
        else if (n >= 33 && n < 66)
            computer = 'P';
        else
            computer = 'S';

        printf("\nEnter R for ROCK, P for PAPER, and S for SCISSOR: ");
        scanf(" %c", &player);
        player = toupper(player);

        result = game(player, computer);

        if (result == -1) {
            printf("\nGame Draw!\n");
        } else if (result == 1) {
            printf("\nWow! You have won this round!\n");
            playerScore++;
        } else {
            printf("\nOh! You have lost this round!\n");
            computerScore++;
        }

        printf("You chose: %c, Computer chose: %c\n", player, computer);
        rounds++;
    }

    printf("\nFinal Score -> You: %d | Computer: %d\n", playerScore, computerScore);
    
    if (playerScore > computerScore)
        printf("\nCongratulations! You are the overall winner!\n");
    else if (playerScore < computerScore)
        printf("\nComputer wins! Better luck next time!\n");
    else
        printf("\nIt's a tie! Well played!\n");
    
    return 0;
}
