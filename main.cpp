#include <iostream>
#include <Engine.h>

int WinMain(int argc, char *argv[]) {
    Engine Game;
    InputControle input;
    Game.Init("game",1200,700);
    Game.camera.SetPosition({-600,-350});

    SDL_Texture * pro = Game.CreateTexture("../img/pro.jpg");
    SDL_Rect player = {0,0,300,100};
    SDL_Rect wall = {900,350,50,350};
    Vec2 playerPosition = {0,0};
    

    while(!input.GetExit()){
        input.KeyEvent();
        Game.Clean();

        if(input.KeyIsPressed(SDLK_DOWN)) playerPosition.y+=100  * Game.deltaTime; 
        if(input.KeyIsPressed(SDLK_UP)) playerPosition.y-=100 * Game.deltaTime; 
        if(input.KeyIsPressed(SDLK_LEFT)) playerPosition.x-=300 * Game.deltaTime; 
        if(input.KeyIsPressed(SDLK_RIGHT)) playerPosition.x+=300 * Game.deltaTime; 
        if(input.KeyDown(SDLK_SPACE)) Game.camera.ActiveFollow(playerPosition);
        if(input.KeyDown(SDLK_p)) Game.camera.DeactivateFollow();
        if(input.KeyDown(SDLK_m)) std::cout<<Game.deltaTime;
        

        player.x = playerPosition.x;
        player.y = playerPosition.y;

        Game.DrawTexture(pro,{0,0,0,0},player);
        Game.DrawRect(wall,Game.hexToRGB("fff"));
        Game.Update(41,input);
    }
    
    return 0;
}
