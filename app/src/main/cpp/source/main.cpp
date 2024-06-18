//
// Created by davidng on 6/18/24.
//


#include <chrono>

#include <game-activity/GameActivity.cpp>
#include <game-text-input/gametextinput.cpp>
#include "../hpp/Game.h"
#include "../hpp/logging.h"


extern "C"{
#include <game-activity/native_app_glue/android_native_app_glue.c>

void handleAppCmd(android_app * app, int32_t cmd){
    if(cmd == APP_CMD_INIT_WINDOW){
        LOGD("Init window!");
        Game * game = new Game();
        game->begin(app);
        app->userData = game;
    } else if(cmd == APP_CMD_TERM_WINDOW){
        LOGD("Exiting app!");
        Game * game = reinterpret_cast<Game *>(app->userData);
        app->userData = nullptr;
        delete game;
    }
}
void android_main(android_app * app){
    LOGD("Entering android_main");
    app->onAppCmd = handleAppCmd;
    int events;
    android_poll_source *pSource;
    auto lastTime = std::chrono::high_resolution_clock::now();

    do{
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> deltaTime = currentTime - lastTime;
        if(ALooper_pollAll(0, nullptr, &events, (void **)&pSource) >= 0){
            if(pSource){
                pSource->process(app, pSource);
            }

        }
        if(app->userData){
            Game *game = reinterpret_cast<Game *>(app->userData);
            game->update(deltaTime.count());
        }

    }while(!app->destroyRequested);
}

}