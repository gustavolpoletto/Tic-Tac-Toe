#ifndef DESIGN_H
#define DESIGN_H

#include "raylib.h"
#include <stdio.h>
#include <string.h>

#define HEIGHT 600
#define WIDTH 600
#define FINAL_TEXT_SIZE 80
#define CURRENT_MODE_TEXT_SIZE 30
#define RESTART_TEXT_SIZE 20

// extern Font FontX;
extern int gameStarted;
extern int optionMenu;

void initGameWindow();
void DrawGame();
void closeGame();

void DrawMenu();
void DrawOptionMenu();

void drawBoard();
void DrawFinal();

#endif
