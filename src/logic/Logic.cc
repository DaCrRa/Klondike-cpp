/*
 * KlondikeAppStateContext.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <Logic.h>

#include <UserGameActionController.h>
#include <RandomGameActionController.h>

Logic::Logic() :
    statesBuildr(*this,
                 game,
                 gameActionControllerHolder,
                 historyController,
                 bestScoresController,
                 saveGameController),
    currentState(statesBuildr.getInitialState()),
    bestScoresController(new BestScoresController(game)),
    saveGameController(new SaveGameController(*this, game)) {
    assert(currentState);
}

ControllerPtr Logic::getNextController() {
    return currentState->getController();
}

void Logic::gameStarted() {
    currentState = currentState->transitionToGameInProgress();
}

void Logic::saveGameRequested() {
    currentState = currentState->transitionToSavingGame();
}

void Logic::gamePauseRequested() {
    currentState = currentState->transitionToNoGameInProgress();
}

void Logic::gameResumeRequested() {
    currentState = currentState->transitionToGameInProgress();
}

void Logic::gameCompleted() {
    bestScoresController->registerScore();
    currentState = currentState->transitionToGameCompleted();
}

void Logic::exitRequested() {
    currentState = currentState->transitionToExit();
}
