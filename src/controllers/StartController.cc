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

void StartController::start(std::shared_ptr<GameActionController> gameActionController) {
    std::shared_ptr<Klondike> game(new Klondike());
    sessionStarter.startSession(game, gameActionController);
    eventObserver.gameStarted();
}

StartController::StartController(GameSessionStarter& starter,
                                 GameStatePtr s,
                                 EventObserver& observer) :
    sessionStarter(starter),
    gameState(s),
    eventObserver(observer) { }

void StartController::startGame() {
    start(std::shared_ptr<GameActionController>(new UserGameActionController(eventObserver)));
}

void StartController::startDemo() {
    start(std::shared_ptr<GameActionController>(new RandomGameActionController(eventObserver)));
}

bool StartController::isGameInProgress() {
    return gameState->gameIsStarted();
}

void StartController::accept(ControllerVisitor* v) {
    v->visit(this);
}
