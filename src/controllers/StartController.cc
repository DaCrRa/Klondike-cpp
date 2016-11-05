/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>
#include <GameActionHistoryController.h>

#include <assert.h>

StartController::StartController(GameStatePtr s, EventObserver& observer) :
    gameState(s),
    eventObserver(observer) { }

void StartController::startGame() {
    eventObserver.userGameStartRequested();
}

void StartController::saveGame() {
    eventObserver.saveGameRequested();
}

void StartController::startDemo() {
    eventObserver.demoRequested();
}

void StartController::resumeGame() {
    eventObserver.gameResumeRequested();
}

void StartController::terminateApp() {
    eventObserver.exitRequested();
}

bool StartController::isGameInProgress() {
    return gameState->gameIsStarted();
}

void StartController::accept(ControllerVisitor* v) {
    v->visit(this);
}
