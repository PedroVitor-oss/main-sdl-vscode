#ifndef ANIMATION_H
#define ANIMATION_H

#include <Engine.h>
#include <vector>
#include <iostream>

struct Frame
{
        int iSprite;
        int iTexture;
};

class Animation
{
public:
        SpriteGame GetSprite();    // chama dentro do draw Texture;
        SDL_Texture *GetTexture(); // chama dentro do draw texture

        // void AddSprite(SpriteGame sprite); não vamos mais usar desse modo
        void LoadAniamtion(std::string pathAnimation, std::string pathTextures, Engine &engine); // quando o arquivo não diz o diretoria das imagens
        void LoadAniamtion(std::string pathAnimation, Engine &engine);                           // quando o arquivo passa todas as informações nessessarias

        int GetLength();

        void SetTimeUpdate(int time); // velocidade da atualização
        void Update();

private:
        int temp = 0;
        int frame = 0;
        int timeUpdate = 10;

        std::vector<SpriteGame> sprites;
        std::vector<SDL_Texture *> textures;
        std::vector<Frame> frames;

protected:
private:
};

#endif // ANIMATION_H
