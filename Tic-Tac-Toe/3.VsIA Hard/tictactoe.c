#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Position{
    int i;
    int j;
}position;

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
void showNumBoard ();
void ShowColorTab();

int main()
{
    srand(time(NULL));
    Inicialize();


    while(!tied() && !victory())
    {
        system("cls");
        showNumBoard();
        ShowTab();
        play();
        if (!tied() && !victory())
            IAplay();
    }
    system("cls");
    printf("\n--FINAL BOARD--\n");
    ShowTab();

    int winner = victory();
    if(winner != 0)
    {
        if (winner == 1)
        printf("\033[1;34mWINNER - Player\033[0m\n");
        else
        printf("\033[1;31mWINNER - IA\033[0m\n");
    }

    else
    printf("\033[1;33mThat's a TIE\033[0m\n");


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
        
        playNum = playNum - 1;
        i = playNum / 3;
        j = playNum % 3;

    }while(!legalPlay(i, j));

    board[i][j] = 'X';
}

void IAplay()
{
    int i , j;
    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'O';
                if (victory())
                {
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'X';
                if (victory())
                {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    if (board[1][1] == '-')
    {
        board[1][1] = 'O';
        return;
    }

    int play;
    position corner[4] = { {0 , 0} , {0 , 2} , {2 , 0}, {2 , 2}};
    position side[4] = {{0 , 1} , {1 , 0} , {1 , 2}, {2 , 1}};

    // If player goes to the middle [1][1] -> bot goes to corners
    if (board[1][1] == 'X')
    {
        for (int x = 0 ; x < 4; x++)
        {
            if (board[corner[x].i][corner[x].j] == '-')
            {
                do {
                    play = rand() % 4;
            }while(board[corner[play].i][corner[play].j] != '-');
            board[corner[play].i][corner[play].j] = 'O';
            return;
        }
    }

    do{
        play = rand() % 4;
    }while(board[side[play].i][side[play].j] != '-');

    board[side[play].i][side[play].j] = 'O';
    return;
   }

   // If player don't goes to the middle [1][1] -> bot goes to sides
   for (int x = 0 ; x < 4; x++)
        {
            if (board[side[x].i][side[x].j] == '-')
            {
                do {
                    play = rand() % 4;
            }while(board[side[play].i][side[play].j] != '-');
            board[side[play].i][side[play].j] = 'O';
            return;
        }
    }

    do{
        play = rand() % 4;
    }while(board[corner[play].i][corner[play].j] != '-');

    board[corner[play].i][corner[play].j] = 'O';
    return;
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
    if (i>=0 && i < 3 && j>=0 && j < 3 && board[i][j] == '-')
        return true;
    return false;
}

void showNumBoard ()
{
    int a = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", a++);
        }
        printf("\n");
    }
    printf("\n");
}


void ShowColorTab()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ( (i+j) % 2 == 0 )
                printf("\033[37;40m %c \033[0m", board[i][j]);
            else
                printf("\033[30;47m %c \033[0m", board[i][j]);
                
        }
        printf("\n");
    }
}