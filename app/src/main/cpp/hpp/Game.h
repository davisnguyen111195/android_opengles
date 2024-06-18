//
// Created by davidng on 6/18/24.
//

#ifndef FIRSTPROJECT_GAME_H
#define FIRSTPROJECT_GAME_H

#include <game-activity/native_app_glue/android_native_app_glue.h>
#include "../hpp/Renderer.h"

class Game{
public:
    void begin(android_app * app);
    void update(float deltaTime);
private:
    Renderer renderer;
};


#endif //FIRSTPROJECT_GAME_H
