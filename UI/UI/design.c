#include "design.h"
#include "../game/game.h"

Font FontX;
Texture2D backgroundBoard;

void initGameWindow(){
    InitWindow(WIDTH, HEIGHT, "Tic-Tac-Toe");
    SetTargetFPS(60);

    FontX = LoadFontEx("fonts/ClarityCity-Medium.ttf", 300, 0, 0);
    backgroundBoard = LoadTexture("assets/board.png");   
}

void DrawGame(){
    BeginDrawing();
        drawBoard();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mousePos = GetMousePosition();
            makePlay(mousePos.y / (HEIGHT /3), mousePos.x/ (WIDTH / 3));
        }

    EndDrawing();
}

void DrawFinal(){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        drawBoard();

        if (victory()){
            char text[] = "WINNER - O";
            if (currentPlayer == 'O') text[9] = 'X';

            
            Vector2 length = MeasureTextEx(FontX, text, FINAL_TEXT_SIZE, 10);
            DrawTextEx(FontX, text, (Vector2){(WIDTH - length.x) / 2, (HEIGHT - length.y) /2}, FINAL_TEXT_SIZE, 10, BLACK );
        }

        else{
            const char *text = "THAT'S A TIE";
            int length = MeasureText(text, FINAL_TEXT_SIZE);
            DrawText(text, (WIDTH - length) / 2, (HEIGHT - FINAL_TEXT_SIZE) /2, FINAL_TEXT_SIZE, BLACK );
        }

        const char *restart_text = "Press ENTER to restart";
        int length = MeasureText(restart_text, RESTART_TEXT_SIZE);
        DrawText(restart_text, (WIDTH - length) / 2, (HEIGHT + FINAL_TEXT_SIZE) /2, RESTART_TEXT_SIZE, BLACK );

        if (IsKeyPressed(KEY_ENTER)){
            Inicialize();
            currentPlayer = 'X';
        } 
            

    EndDrawing();
}

void closeGame(){
    UnloadFont(FontX);
    UnloadTexture(backgroundBoard);
    CloseWindow();
}

void drawBoard(){

    Rectangle source = {0,0,backgroundBoard.width,backgroundBoard.height};
    Rectangle destination = {0,0,WIDTH,HEIGHT};
    Vector2 origin = {0, 0};
    DrawTexturePro(backgroundBoard,source,destination,origin,0,WHITE);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (board[i][j] == 'X') {
                char * text = "X";
                int size = (HEIGHT/ 2) * 0.8;
                Vector2 lenght = MeasureTextEx(FontX, text, size, 0);
                DrawTextEx(FontX, "X", (Vector2){WIDTH/6 + WIDTH/3*j - lenght.x / 2, HEIGHT/6 + HEIGHT/3*i - lenght.y / 2} , size, 0, RED);
            }

            if (board[i][j] == 'O') DrawRing((Vector2){WIDTH/6 + WIDTH/3*j,  WIDTH/6 + WIDTH/3*i}, 0.6 * (WIDTH / 6) - 15, 0.6 * (WIDTH / 6), 0, 360,64,BLUE);
        }
    }
}

