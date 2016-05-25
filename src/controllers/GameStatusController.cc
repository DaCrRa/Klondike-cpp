/*
 * GameStatusController.cpp
 *
 *  Created on: 24 de may. de 2016
 *      Author: dancre
 */

#include <GameStatusController.h>

#include <assert.h>

GameStatusController::GameStatusController(std::shared_ptr<Klondike>& game) :
    game(game) {}

void GameStatusController::startNewGame() {
    game = std::shared_ptr<Klondike>(new Klondike());
    game->initialize();
}

bool GameStatusController::isGameInProgress() {
    return (bool)game;
}

void GameStatusController::pauseGame() {
    assert(!game->isPaused());
    game->togglePause();
}

void GameStatusController::resumeGame() {
    assert(game->isPaused());
    game->togglePause();
}
