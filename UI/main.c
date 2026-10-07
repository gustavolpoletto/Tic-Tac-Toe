#include "game/game.h"
#include "UI/design.h"
#include "raylib.h"

int main(){
    initGameWindow();
    Inicialize();
    
    while(!WindowShouldClose()){
        if (!gameStarted){
            if(optionMenu)
                DrawOptionMenu();
            else
                DrawMenu();
        }

        else if (!tied() && !victory()){
            DrawGame();
        }

        else{
            DrawFinal();
        }
    }

    closeGame();
}