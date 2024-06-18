//
// Created by davidng on 6/18/24.
//

#ifndef FIRSTPROJECT_RENDERER_H
#define FIRSTPROJECT_RENDERER_H
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <game-activity/native_app_glue/android_native_app_glue.h>
#include "logging.h"


class Renderer{
public:
    void init(android_app *app);
    static void beginUpdate();
    void endUpdate();
private:
    EGLDisplay display;
    EGLConfig config;
    EGLSurface surface;
    EGLContext context;

};
#endif //FIRSTPROJECT_RENDERER_H
