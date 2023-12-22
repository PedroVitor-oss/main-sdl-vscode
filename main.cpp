#include <iostream>
#include <string>
#include <Engine.h>

Engine Game;
InputControle input;

// class Cuphead{
//     public
// };

void Menu();
void Tutorial();

int WinMain(int argc, char *argv[])
{
    Game.Init("game", 1200, 700);

    Game.scene.adicionarCena(Menu);
    Game.scene.adicionarCena(Tutorial);

    Game.scene.setCenaAtual(0);
    while (1)
    {
        Game.scene.chamarCenaAtual();
    }

    return 0;
}
void Tutorial()
{
    SDL_Texture *bg = Game.CreateTexture("../img/Tutorial/Tutorial (First)/Drawing/tutorial_room_back_layer_0001.png");
    SDL_Texture *bg2 = Game.CreateTexture("../img/Tutorial/Tutorial (First)/Drawing/tutorial_room_front_layer_0001.png");

    Game.DrawTexture(bg, {0, 0, 0, 0}, {0, 0, 1200, 700});
    Game.Update(41, input);
    while (!input.GetExit() && Game.scene.GetIndexCena() == 1)
    {
        input.KeyEvent();
    }
}
void Menu()
{
    SDL_Texture *bg = Game.CreateTexture("../img/title screen/Background/title_screen_background.png");
    SDL_Texture *cuphead[34];
    float frame = 0;
    int direction = 1;
    for (int i = 0; i < 34; i++)
    {
        std::string path = i < 9 ? "../img/title screen/Cuphead and Mugman/cuphead_title_screen_000" + std::to_string(i + 1) + ".png" : "../img/title screen/Cuphead and Mugman/cuphead_title_screen_00" + std::to_string(i + 1) + ".png";
        cuphead[i] = Game.CreateTexture(path);
    }

    while (!input.GetExit() && Game.scene.GetIndexCena() == 0)
    {
        input.KeyEvent();
        Game.DrawTexture(bg, {0, 0, 0, 0}, {0, 0, 1200, 700});
        Game.DrawTexture(cuphead[int(frame)], {0, 0, 0, 0}, {0, 0, 1200, 700});
        frame += direction;
        if (frame >= 32 || frame <= 0)
            direction *= -1;
        Game.Update(41, input);
        if (input.KeyDown())
        {
            Game.scene.setCenaAtual(1);
        }
    }
}