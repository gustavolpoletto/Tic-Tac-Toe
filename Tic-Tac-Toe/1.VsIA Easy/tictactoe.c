#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char board[3][3];
char currentPlayer = 'X';

void ShowTab ();
void Inicialize();
int victory();
bool tied();
char current();
void play();
bool legalPlay(int i , int j);
void IAplay();

int main()
{
    srand(time(NULL));
    Inicialize();


    while(!tied() && !victory())
    {
        system("clear");
        ShowTab();
        play();
        if (!tied() && !victory())
            IAplay();
    }
    system("clear");
    printf("\n--FINAL BOARD--\n");
    ShowTab();

    int winner = victory();
    if(winner != 0)
    {
        if (winner == 1)
        printf("WINNER - Player\n");
        else
        printf("WINNER - IA\n");
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

    board[i][j] = 'X';
}

void IAplay()
{
    if (board[1][1] == '-')
    {
        board[1][1] = 'O';
        return;
    }
    int IAi , IAj;
    do {
        IAi = rand() % 3;
        IAj = rand() % 3;
    }while(board[IAi][IAj] != '-');

    board[IAi][IAj] = 'O';
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

int victory()
{
        for(int i=0;i<3;i++){
        if(board[i][0]=='X' && board[i][0]==board[i][1] && board[i][1]==board[i][2]) return 1;
        if(board[0][i]=='X' && board[0][i]==board[1][i] && board[1][i]==board[2][i]) return 1;
        if(board[i][0]=='O' && board[i][0]==board[i][1] && board[i][1]==board[i][2]) return 2;
        if(board[0][i]=='O' && board[0][i]==board[1][i] && board[1][i]==board[2][i]) return 2;
    }

    if(board[0][0]=='X' && board[0][0]==board[1][1] && board[1][1]==board[2][2]) return 1;
    if(board[0][2]=='X' && board[0][2]==board[1][1] && board[1][1]==board[2][0]) return 1;
    if(board[0][0]=='O' && board[0][0]==board[1][1] && board[1][1]==board[2][2]) return 2;
    if(board[0][2]=='O' && board[0][2]==board[1][1] && board[1][1]==board[2][0]) return 2;

    return 0;
}

bool legalPlay(int i , int j)
{
    if (board[i][j] == '-')
        return true;
    return false;
}
