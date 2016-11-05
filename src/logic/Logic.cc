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
    statesBuildr(*this, game, historyController, bestScoresController, saveGameController),
    currentState(statesBuildr.getInitialState()),
    bestScoresController(new BestScoresController(*this, game)),
    saveGameController(new SaveGameController(*this, game)) {
    assert(currentState);
}

ControllerPtr Logic::getNextController() {
    return currentState->getController();
}

void Logic::start(std::shared_ptr<GameActionController> gameActionController) {
    game = std::shared_ptr<Klondike>(new Klondike());
    game->initialize();
    historyController = std::shared_ptr<GameActionHistoryController>(new GameActionHistoryController());
    statesBuildr.setGameActionController(gameActionController);
    currentState = currentState->transitionToGameInProgress();
}

void Logic::userGameStartRequested() {
    start(std::shared_ptr<GameActionController>(new UserGameActionController(*this, game, historyController)));
}

void Logic::demoRequested() {
    start(std::shared_ptr<GameActionController>(new RandomGameActionController(*this, game)));
}

void Logic::saveGameRequested() {
    currentState = currentState->transitionToSavingGame();
}

void Logic::gameSaved() {
    currentState = currentState->transitionToNoGameInProgress();
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
