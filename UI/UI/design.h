#ifndef DESIGN_H
#define DESIGN_H

#include "raylib.h"

#define HEIGHT 600
#define WIDTH 600
#define FINAL_TEXT_SIZE 80
#define RESTART_TEXT_SIZE 20

 extern Font FontX;

void initGameWindow();
void DrawGame();
void closeGame();

void drawBoard();
void DrawFinal();

#endif