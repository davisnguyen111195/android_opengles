//
// Created by davidng on 6/18/24.
//
#include "../hpp/Renderer.h"

void Renderer::init(android_app * app){
    constexpr EGLint attribs[] = {
            EGL_RENDERABLE_TYPE,
            EGL_OPENGL_ES2_BIT,
            EGL_SURFACE_TYPE,
            EGL_WINDOW_BIT,
            EGL_BLUE_SIZE,
            EGL_WINDOW_BIT,
            EGL_BLUE_SIZE,
            8,
            EGL_GREEN_SIZE,
            8,
            EGL_DEPTH_SIZE,
            24,
            EGL_NONE
    };
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if(eglInitialize(display, nullptr, nullptr) == EGL_FALSE){
        LOGE("Failed to initialize EGL display! Error code: %d", eglGetError());
    }

    EGLint numConfig;
    eglChooseConfig(display,
                    attribs,
                    &config,
                    1,
                    &numConfig);
    surface = eglCreateWindowSurface(display,
                                     config,
                                     app->window,
                                     nullptr);
    if(surface == EGL_NO_SURFACE){
        LOGE("Failed to create EGL surface! Error code: %d", eglGetError());
    }
    EGLint contextAttribs[] = {
            EGL_CONTEXT_CLIENT_VERSION,
            2,
            EGL_NONE
    };
    context = eglCreateContext(display,
                               config,
                               nullptr,
                               contextAttribs);
    eglMakeCurrent(display,
                   surface,
                   surface,
                   context);
    if(context == EGL_NO_CONTEXT){
        LOGE("Failed to initialize EGL context! Error code: %d", eglGetError());
    }
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void Renderer::beginUpdate() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::endUpdate(){
    if(eglSwapBuffers(display, surface) == EGL_FALSE){
        LOGE("EGL error while swapping buffers! Error code: %d", glGetError());
    }
}
