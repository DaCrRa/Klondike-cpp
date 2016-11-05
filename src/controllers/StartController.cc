/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>
#include <GameActionHistoryController.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>

#include <assert.h>

void StartController::start(std::shared_ptr<GameActionController> gameActionController) {
    game = std::shared_ptr<Klondike>(new Klondike());
    game->initialize();
    historyController = std::shared_ptr<GameActionHistoryController>(new GameActionHistoryController());
    gameActionControllerHolder.setGameActionController(gameActionController);
    eventObserver.gameStarted();
}

StartController::StartController(std::shared_ptr<Klondike>& g,
                                 std::shared_ptr<GameActionHistoryController>& h,
                                 GameActionControllerHolder& gameActionControllerHolder,
                                 GameStatePtr s,
                                 EventObserver& observer) :
    game(g),
    historyController(h),
    gameActionControllerHolder(gameActionControllerHolder),
    gameState(s),
    eventObserver(observer) { }

void StartController::startGame() {
    start(std::shared_ptr<GameActionController>(new UserGameActionController(eventObserver, game, historyController)));
}

void StartController::startDemo() {
    start(std::shared_ptr<GameActionController>(new RandomGameActionController(eventObserver, game)));
}

bool StartController::isGameInProgress() {
    return gameState->gameIsStarted();
}

void StartController::accept(ControllerVisitor* v) {
    v->visit(this);
}
