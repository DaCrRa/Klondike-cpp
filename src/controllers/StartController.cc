/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>
#include <GameInProgressState.h>
#include <DemoInProgressState.h>
#include <GameActionHistoryController.h>

#include <assert.h>

StartController::StartController(KlondikeAppStateContext& cntxt) :
    context(cntxt) { }

void StartController::startGame() {
    context.getGame() = std::shared_ptr<Klondike>(new Klondike);
    context.getHistoryController() = std::shared_ptr<GameActionHistoryController>(
                                         new GameActionHistoryController());
    context.getGame()->initialize();
    context.setState(KlondikeAppStatePtr(new GameInProgressState()));
}

void StartController::startDemo() {
    context.getGame() = std::shared_ptr<Klondike>(new Klondike);
    context.getGame()->initialize();
    context.setState(KlondikeAppStatePtr(new DemoInProgressState()));
}

void StartController::resumeGame() {
    context.setState(KlondikeAppStatePtr(new GameInProgressState()));
}

void StartController::terminateApp() {
    context.resetState();
}

bool StartController::isGameInProgress() {
    return (bool)context.getGame();
}

void StartController::accept(ControllerVisitor* v) {
    v->visit(this);
}
