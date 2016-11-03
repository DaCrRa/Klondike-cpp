/*
 * GamePausedState.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <NoGameInProgress.h>

#include <AppStatesBuilder.h>

NoGameInProgressState::NoGameInProgressState(AppStatesBuilder& sb,
        EventObserver& observer,
        GameStatePtr gs) :
    AppState(sb),
    eventObserver(observer),
    gameState(gs) {}

ControllerPtr NoGameInProgressState::getController() {
    return ControllerPtr(new StartController(gameState, eventObserver));
}

AppStatePtr NoGameInProgressState::transitionToExit() {
    return statesBuilder.getExitState();
}

AppStatePtr NoGameInProgressState::transitionToGameInProgress() {
    return statesBuilder.getGameInProgressState();
}
