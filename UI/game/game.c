#include "game.h"

char board[3][3];
char currentPlayer = 'X';
int mode = 0;

typedef struct Position{
    int i;
    int j;
}position;

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

char current()
{
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
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
            if (board[i][j] == '-')
                return false;
        }
    }

    return true;
}

bool victory()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != '-' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;

        if (board[0][i] != '-' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] != '-' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] != '-' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

bool legalPlay(int i, int j)

{
    return board[i][j] == '-';
}

int minimax(bool maximizing, int depth){
    int result = MINIMAX_victory();
    if (result == 2) return 10 - depth;
    if (result == 1) return depth - 10;
    if(tied())return 0;
    
    int bestScore;
    if (maximizing){  //maximizing == true -> IA turn
        bestScore = -100;
        for (int i = 0 ; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
                if (board[i][j] == '-'){
                    board[i][j] = 'O';
                    int currentScore = minimax(false, depth + 1);
                    board[i][j] = '-';
                    if (currentScore > bestScore) bestScore = currentScore;
                }
            }
        }
    }
    
    else{
        bestScore = 100;
        for (int i = 0 ; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
                if (board[i][j] == '-'){
                    board[i][j] = 'X';
                    int currentScore = minimax(true, depth + 1);
                    board[i][j] = '-';
                    if (currentScore < bestScore) bestScore = currentScore;
                }
            }
        }
    }
    
    
    return bestScore;
}

int MINIMAX_victory()
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

void IAplayIMP(){
    int posi = -1, posj = -1, bestScore = -100;
    
    for (int i = 0 ; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            if (board[i][j] == '-'){
                board[i][j] = 'O';
                int currentScore = minimax(false, 0);
                board[i][j] = '-';
                if (currentScore > bestScore){
                    bestScore = currentScore;
                    posi = i;
                    posj = j;
                } 
            }
        }
    }
    
    board[posi][posj] = current();
}

void IAplayHARD()
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
                    current();
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
                    board[i][j] = current();
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    if (board[1][1] == '-')
    {
        board[1][1] = current();
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
            board[corner[play].i][corner[play].j] = current();
            return;
        }
    }

    do{
        play = rand() % 4;
    }while(board[side[play].i][side[play].j] != '-');

    board[side[play].i][side[play].j] =  current();
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
            board[side[play].i][side[play].j] = current();
            return;
        }
    }

    do{
        play = rand() % 4;
    }while(board[corner[play].i][corner[play].j] != '-');

    board[corner[play].i][corner[play].j] = current();
    return;
}

void IAplayMEDIUM()
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
                    current();
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
                    board[i][j] = current();
                    return;
                }
                board[i][j] = '-';
            }
        }
    }


    if (board[1][1] == '-')
    {
        board[1][1] = current();
        return;
    }
    int IAi , IAj;
    do {
        IAi = rand() % 3;
        IAj = rand() % 3;
    }while(board[IAi][IAj] != '-');

    board[IAi][IAj] = current();
    return;
}

void IAplayEASY()
{
    if (board[1][1] == '-')
    {
        board[1][1] = current();
        return;
    }
    int IAi , IAj;
    do {
        IAi = rand() % 3;
        IAj = rand() % 3;
    }while(board[IAi][IAj] != '-');

    board[IAi][IAj] = current();
}

void makePlay(int i, int j)
{
    if (legalPlay(i, j)){
        board[i][j] = current();
        if (mode && !tied() && !victory()){
            switch (mode){
                case 1:
                    IAplayIMP();
                    break;
                case 2:
                    IAplayHARD();
                    break;
                case 3:
                    IAplayMEDIUM();
                    break;
                case 4:
                    IAplayEASY();
                    break;           
            }
        }

    }
}