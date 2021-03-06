/*
 * KlondikeAppStateContext.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <Logic.h>

#include <UserGameActionController.h>
#include <RandomGameActionController.h>

Logic::Logic(std::shared_ptr<AbstractDeckFactory> factory,
             KlondikeSaver& saver,
             KlondikeLoader& loader,
             std::shared_ptr<AppStatesBuilder> builder) :
    statesBuildr(builder),
    gameSessionStarter(game, gameActionControllerHolder),
    currentState(statesBuildr->getInitialState()),
    bestScoresController(new BestScoresController(game)),
    saveGameController(new SaveGameController(game, saver)),
    loadGameController(new LoadGameController (*this, factory, gameSessionStarter, loader)),
    saver(saver) {
    assert(currentState);
}

ControllerPtr Logic::getNextController() {
    return currentState->getController();
}

void Logic::gameStarted() {
    currentState = currentState->transitionToGameInProgress();
}

void Logic::saveGameRequested() {
    saver.setGame(game);
    currentState = currentState->transitionToSavingGame();
}

void Logic::loadGameRequested() {
    currentState = currentState->transitionToLoadingGame();
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
