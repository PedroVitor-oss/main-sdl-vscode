#include <iostream>
#include <Engine.h>

int WinMain(int argc, char *argv[]) {
    Engine Game;
    InputControle input;
    Game.Init("game",1200,700);

    SDL_Texture * pro = Game.CreateTexture("../img/pro.jpg");
    Game.DrawTexture(pro,{0,0,0,0},{0,0,1200,700});

    Game.Update(41,input);
    while(!input.GetExit()){
        input.KeyEvent();
    }
    
    return 0;
}
