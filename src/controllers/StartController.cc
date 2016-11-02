/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>
//#include <DemoInProgressState.h>
#include <GameActionHistoryController.h>

#include <assert.h>

StartController::StartController(EventObserver& observer) :
    eventObserver(observer) { }

void StartController::startGame() {
    eventObserver.gameStarted();
}

void StartController::startDemo() {
//    context.getGame() = std::shared_ptr<Klondike>(new Klondike);
//    context.getGame()->initialize();
//    context.setState(StatePtr(new DemoInProgressState()));
}

void StartController::resumeGame() {
    eventObserver.gameResumed();
}

void StartController::terminateApp() {
    eventObserver.exitRequested();
}

bool StartController::isGameInProgress() {
    //return (bool)context.getGame();
    return false;
}

void StartController::accept(ControllerVisitor* v) {
    v->visit(this);
}
