/*
 * GameInProgress.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <GameInProgressState.h>

#include <AppStatesBuilder.h>

GameInProgressState::GameInProgressState(AppStatesBuilder& sb,
        std::shared_ptr<GameActionController> gac):
    AppState(sb),
    gameActionController(gac) {}

ControllerPtr GameInProgressState::getController() {
    return ControllerPtr(gameActionController);
}

AppStatePtr GameInProgressState::transitionToNoGameInProgress() {
    return statesBuilder.getPausedState();
}

AppStatePtr GameInProgressState::transitionToGameCompleted() {
    return statesBuilder.getGameCompletedState();
}
