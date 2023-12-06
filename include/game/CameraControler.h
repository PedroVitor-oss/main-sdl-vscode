#ifndef CAMERACONTROLER_H
#define CAMERACONTROLER_H

#include <Vec2.h>

class CameraControler{
    public:
    void SetPosition(Vec2 pos);
    void ActiveFollow(Vec2 &follow);
    void DeactivateFollow();  
    bool FollowIsActive();
    Vec2 GetPosition();

    private:
    Vec2 position  = {0,0};
    bool followActive = false;  // Variável de controle para indicar se o seguimento está ativo
    Vec2 *followTarget = nullptr;  
    Vec2 offset = {0,0};
};

#endif
