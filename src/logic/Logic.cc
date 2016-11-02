/*
 * KlondikeAppStateContext.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <Logic.h>

Logic::Logic() :
    statesBuildr(*this, game, historyController, bestScoresController),
    currentState(statesBuildr.getInitialState()),
    bestScoresController(new BestScoresController(*this, game)) {
    assert(currentState);
}

ControllerPtr Logic::getNextController() {
    return currentState->getController();
}

void Logic::gameStarted() {
    game = std::shared_ptr<Klondike>(new Klondike());
    game->initialize();
    historyController = std::shared_ptr<GameActionHistoryController>(new GameActionHistoryController());
    currentState = currentState->transitionToGameInProgress();
}

void Logic::gamePaused() {
    currentState = currentState->transitionToGamePaused();
}

void Logic::gameResumed() {
    currentState = currentState->transitionToGameInProgress();
}

void Logic::gameCompleted() {
    bestScoresController->registerScore();
    currentState = currentState->transitionToGameCompleted();
}

void Logic::exitRequested() {
    currentState = currentState->transitionToExit();
}
