/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>

#include <assert.h>

StartController::StartController(std::shared_ptr<Klondike>& k, GameActionControllerCatalog& catalog) :
    gameStatusController(k),
    gameActionControllerCatalog(catalog),
    terminateAppFlag(false)
{

}

void StartController::startGame() {
    gameStatusController.startNewGame();
}

void StartController::resumeGame() {
    gameStatusController.resumeGame();
}

void StartController::terminateApp() {
    terminateAppFlag = true;
}

bool StartController::continueApp() {
    return !terminateAppFlag;
}

bool StartController::isGameInProgress() {
    return gameStatusController.isGameInProgress();
}

const std::vector<std::shared_ptr<GameActionController> > StartController::getAvailableGameActionControllers() {
    return gameActionControllerCatalog.getAvailableGameActionControllers();
}

void StartController::setSelectedGameActionController(size_t controller) {
    gameActionControllerCatalog.selectGameActionController(controller);
}

void StartController::accept(ControllerVisitor* v) {
    v->visit(this);
}
