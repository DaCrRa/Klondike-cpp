/*
 * GameInProgress.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <GameInProgressState.h>

#include <AppStatesBuilder.h>

GameInProgressState::GameInProgressState(AppStatesBuilder& sb,
        GameActionControllerHolder& gameActionControllerHolder):
    AppState(sb),
    gameActionControllerHolder(gameActionControllerHolder) {}

ControllerPtr GameInProgressState::getController() {
    return ControllerPtr(gameActionControllerHolder.getGameActionController());
}

AppStatePtr GameInProgressState::transitionToNoGameInProgress() {
    return statesBuilder.getPausedState();
}

AppStatePtr GameInProgressState::transitionToGameCompleted() {
    return statesBuilder.getGameCompletedState();
}
