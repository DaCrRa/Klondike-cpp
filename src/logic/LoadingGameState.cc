/*
 * LoadingGame.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <LoadingGameState.h>

#include <AppStatesBuilder.h>

LoadingGameState::LoadingGameState(AppStatesBuilder& sb, std::shared_ptr<LoadGameController>& lgc) :
    AppState(sb),
    loadGameController(lgc) {}

ControllerPtr LoadingGameState::getController() {
    return ControllerPtr(loadGameController);
}

AppStatePtr LoadingGameState::transitionToGameInProgress() {
    return statesBuilder.getGameInProgressState();
}

AppStatePtr LoadingGameState::transitionToNoGameInProgress() {
    return statesBuilder.getInitialState();
}

