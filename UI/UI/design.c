#include "design.h"
#include "../game/game.h"

Font FontX;
Texture2D backgroundBoard;
Texture2D backgroundMenu;
Texture2D backgroundMode;

int gameStarted = 0;
int optionMenu = 0;

void initGameWindow(){
    InitWindow(WIDTH, HEIGHT, "Tic-Tac-Toe");
    SetTargetFPS(60);

    FontX = LoadFontEx("fonts/ClarityCity-Medium.ttf", 300, 0, 0);
    backgroundBoard = LoadTexture("assets/board.png");
    backgroundMenu = LoadTexture("assets/menu.png");
    backgroundMode = LoadTexture("assets/mode.png");
}

void DrawMenu(){
    BeginDrawing();

    Rectangle source = {0,0,backgroundMenu.width,backgroundMenu.height};
    Rectangle destination = {0,0,WIDTH,HEIGHT};
    Vector2 origin = {0, 0};
    DrawTexturePro(backgroundMenu,source,destination,origin,0,WHITE);

    char CurrentModeText[15];
    switch (mode){
        case 1:
            strcpy(CurrentModeText, "IMPOSSIBLE");
            break;
        case 2:
            strcpy(CurrentModeText, "HARD");
            break;
        case 3:
            strcpy(CurrentModeText, "MEDIUM");
            break;
        case 4:
            strcpy(CurrentModeText, "EASY");
            break;  
        default:         
            strcpy(CurrentModeText, "PVP");
    }
    Vector2 length = MeasureTextEx(FontX, CurrentModeText, CURRENT_MODE_TEXT_SIZE, 0);
    DrawTextEx(FontX, CurrentModeText, (Vector2){(WIDTH - length.x) / 2, 290 - length.y}, CURRENT_MODE_TEXT_SIZE, 0, BLACK );


    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse = GetMousePosition();
        if (mouse.x > 144 && mouse.x < 488 && mouse.y > 293 && mouse.y < 344) optionMenu = 1;
        if (mouse.x > 112 && mouse.x < 488 && mouse.y > 405 && mouse.y < 488) gameStarted = 1;
    }

    EndDrawing();
}

void DrawOptionMenu(){
    BeginDrawing();

    Rectangle source = {0,0,backgroundMode.width,backgroundMode.height};
    Rectangle destination = {0,0,WIDTH,HEIGHT};
    Vector2 origin = {0, 0};
    DrawTexturePro(backgroundMode,source,destination,origin,0,WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse = GetMousePosition();
        if (mouse.x > 244 && mouse.x < 357 && mouse.y > 524 && mouse.y < 549) optionMenu = 0;

        if (mouse.x > 112 && mouse.x < 489 && mouse.y > 129 && mouse.y < 187) { mode = 0;optionMenu = 0;}
        if (mouse.x > 112 && mouse.x < 489 && mouse.y > 206 && mouse.y < 265) { mode = 4;optionMenu = 0;}
        if (mouse.x > 112 && mouse.x < 489 && mouse.y > 284 && mouse.y < 344) { mode = 3;optionMenu = 0;}
        if (mouse.x > 112 && mouse.x < 489 && mouse.y > 365 && mouse.y < 422) { mode = 2;optionMenu = 0;}
        if (mouse.x > 112 && mouse.x < 489 && mouse.y > 440 && mouse.y < 499) { mode = 1;optionMenu = 0;}
        
    }

    EndDrawing();
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

        const char *reset_text = "SPACE to menu";
        int reset_length = MeasureText(reset_text, RESTART_TEXT_SIZE);
        DrawText(reset_text, (WIDTH - reset_length) / 2, (HEIGHT + FINAL_TEXT_SIZE) /2 + RESTART_TEXT_SIZE, RESTART_TEXT_SIZE, BLACK );

        if (IsKeyPressed(KEY_SPACE)){
            gameStarted = 0;
            optionMenu = 0;
            currentPlayer = 'X';
            Inicialize();
        } 
            

    EndDrawing();
}

void closeGame(){
    UnloadFont(FontX);
    UnloadTexture(backgroundBoard);
    UnloadTexture(backgroundMenu);
    UnloadTexture(backgroundMode);
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

