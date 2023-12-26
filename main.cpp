#include <iostream>
#include <string>
#include <Engine.h>
#include <Animation.h>

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
    while (!input.GetExit())
    {
        Game.scene.chamarCenaAtual();
    }

    return 0;
}
void Tutorial()
{
    SDL_Texture *bg = Game.CreateTexture("../img/Tutorial/Tutorial (First)/Drawing/tutorial_room_back_layer_0001.png");
    SDL_Texture *bg2 = Game.CreateTexture("../img/Tutorial/Tutorial (First)/Drawing/tutorial_room_front_layer_0001.png");
    Animation idle;
    idle.LoadAniamtion("../animation/idle.txt", Game);
    idle.SetTimeUpdate(2);

    while (!input.GetExit() && Game.scene.GetIndexCena() == 1)
    {
        Game.Clean();
        idle.Update();

        Game.DrawTexture(bg, {0, 0, 0, 0}, {0, 0, 1200, 700});
        Game.DrawTexture(idle.GetTexture(), idle.GetSprite(), {100, 100, 98, 155});
        Game.Update(41, input);
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