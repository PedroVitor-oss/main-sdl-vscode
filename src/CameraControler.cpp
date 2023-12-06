#include "CameraControler.h"
#include <iostream>

void CameraControler::SetPosition(Vec2 pos){
    CameraControler::position = pos;
}
void CameraControler::ActiveFollow(Vec2 &follow) {
    followTarget = &follow;
    offset = position - follow;
    followActive = true;
}
bool CameraControler::FollowIsActive(){
    return followActive;
    }
void CameraControler::DeactivateFollow() {
    position = *followTarget + offset;
    followActive = false;
    followTarget = nullptr;  // Limpa o ponteiro
}
Vec2 CameraControler::GetPosition(){
     if (followActive && followTarget != nullptr) {
        // Se o seguimento estiver ativo, use a posição do objeto seguido
        return *followTarget + offset;
    } else {
        // Caso contrário, retorne a posição fixa da câmera
        return position;
    }
}
