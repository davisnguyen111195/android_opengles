//
// Created by davidng on 6/18/24.
//
#include <game-activity/GameActivity.cpp>
#include <game-text-input/gametextinput.cpp>

extern "C"{
#include <game-activity/native_app_glue/android_native_app_glue.c>
#include "../hpp/logging.h"
void handleAppCmd(android_app * app, int32_t cmd){
    if(cmd == APP_CMD_INIT_WINDOW){
        LOGD("Init window!");
    } else if(cmd == APP_CMD_TERM_WINDOW){
        LOGD("Exiting app!");
    }
}
void android_main(android_app * app){
    LOGD("Entering android_main");
    app->onAppCmd = handleAppCmd;
    int events;
    android_poll_source *pSource;
    do{
        if(ALooper_pollAll(0, nullptr, &events, (void **)&pSource) >= 0){
            if(pSource){
                pSource->process(app, pSource);
            }

        }


    }while(!app->destroyRequested);
}

}