/* In VS Code
BUILD:  CTRL+SHIFT+B
RUN: .\tictactoe
*/

/*
    TIC TAC TOE GAME Sketch

Player 1 (X)    -    Player 2 (O)

         |        |
    1    |   2    |  3
  ---------------------
         |        |
    4    |   5    |  6
  ---------------------
         |        |
    7    |   8    |  9

    Player 1, enter a number: 
    ...
    Player 2, enter a number:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char square[9] = {
    '0', '1', '2',
    '3', '4', '5',
    '6', '7', '8'};
int player = 1;
char mark;
int i;
int choice;

void makeBoard();
int checkResults();

int main()
{
    do
    {
        makeBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, choose a number: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 0 && square[0] == '0')
            square[0] = mark;
        else if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else
        {
            printf("Invalid move!");
            --player;
            getch();
        }
        i = checkResults();
        ++player;
    } while (i == -1);

    makeBoard();

    if (i == 1)
    {
        --player;
        printf("\t\t\t\t\tPlayer %d WON!!!\n\n", player);
    }
    else
    {
        printf("\t\t\t\t\t Game is a TIE !!!");
    }
    getch();
    return 0;
}

// Function returning the game status
// 1 = Game finished and there is a winner
// 0 = Game finished in a tie
// -1 = Game is still in progress

int checkResults()
{
    //check if there is a winning combination
    if (square[0] == square[1] && square[1] == square[2])
        return 1;
    else if (square[3] == square[4] && square[4] == square[5])
        return 1;
    else if (square[6] == square[7] && square[7] == square[8])
        return 1;
    else if (square[0] == square[3] && square[3] == square[6])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[0] == square[4] && square[4] == square[8])
        return 1;
    else if (square[2] == square[4] && square[4] == square[6])
        return 1;
    //check to see that there are no more possible moves, i.e. game finished a TIE
    else if (square[0] != '0' && square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8')
        return 0;
    else
        return -1;
}

// Function to print the game board

void makeBoard()
{
    system("cls");
    printf("\n\n\t\t\t\t\t-----Tic Tac Toe Game-----\n\n");
    printf("\t\t\t\t\tPlayer 1 (X) - Player 2 (O)\n\n");

    printf("\t\t\t\t\t\t|\t|\n");
    printf("\t\t\t\t\t   %c    |   %c   |   %c   \t\n", square[0], square[1], square[2]);

    printf("\t\t\t\t\t________|_______|________\n");
    printf("\t\t\t\t\t        |       |         \n");

    printf("\t\t\t\t\t   %c    |   %c   |   %c   \t\n", square[3], square[4], square[5]);

    printf("\t\t\t\t\t________|_______|________\n");
    printf("\t\t\t\t\t        |       |         \n");

    printf("\t\t\t\t\t   %c    |   %c   |   %c   \t\n", square[6], square[7], square[8]);

    printf("\t\t\t\t\t \t|\t|\t\n"); /*same as printf("\t        |       |         \n"); */
}
