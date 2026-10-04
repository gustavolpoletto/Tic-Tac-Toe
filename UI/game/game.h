#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

extern char board[3][3];
extern char currentPlayer;

void Inicialize();
bool victory();
bool tied();
char current();
void makePlay(int i, int j);
bool legalPlay(int i , int j);
void IAplayIMP();
int minimax(bool maximizing, int depth);
int MINIMAX_victory();

#endif