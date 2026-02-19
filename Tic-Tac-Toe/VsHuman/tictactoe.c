#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char board[3][3];
char currentPlayer = 'X';

void ShowTab ();
void Inicialize();
bool victory();
bool tied();
char current();
void play();
bool legalPlay(int i , int j);

int main()
{
    Inicialize();

    while(!tied() && !victory())
    {
        system("clear");
        ShowTab();
        play();
    }
    system("clear");
    printf("\n--FINAL BOARD--\n");
    ShowTab();

    if(victory())
    {
        if (currentPlayer == 'X')
        printf("WINNER - %c\n", 'O');
        else
        printf("WINNER - %c\n", 'X');
    }

    else
        printf("That's a TIE!\n");

    return 0;
}

void Inicialize()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void ShowTab()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void play()
{
    char playSqr[100];
    int playNum, i = 0, j = 0;
    do{
        do{
            printf("Play: ");
            scanf(" %99s", playSqr);
        }while(sscanf(playSqr, "%d", &playNum) != 1);


        i = playNum / 3;
        j = playNum % 3;
    }while(!legalPlay(i, j));

    board[i][j] = current();
}

char current()
{
    if (currentPlayer == 'X')
    {
        currentPlayer ='O';
        return 'X';
    }
    currentPlayer = 'X';
    return 'O';
}

bool tied()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] == '-')
                return false;
        }
    }
    return true;
}

bool victory()
{
        for(int i=0;i<3;i++){
        if(board[i][0]!='-' && board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
        if(board[0][i]!='-' && board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    }

    if(board[0][0]!='-' && board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if(board[0][2]!='-' && board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;

    return false;
}

bool legalPlay(int i , int j)
{
    if (board[i][j] == '-')
        return true;
    return false;
}
