//
// Created by davidng on 6/18/24.
//
#include "../hpp/Game.h"


void Game::begin(android_app * app) {
    renderer.init(app);
}

void Game::update(float deltaTime) {
    renderer.beginUpdate();

    renderer.endUpdate();
}