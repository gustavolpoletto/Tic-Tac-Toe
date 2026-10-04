#include "game/game.h"
#include "UI/design.h"
#include "raylib.h"

int main(){
    initGameWindow();
    Inicialize();
    
    while(!WindowShouldClose()){
        if (!tied() && !victory()){
            DrawGame();
        }
        else{
            DrawFinal();
        }
        
    }

    closeGame();
}