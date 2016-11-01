/*
 * GamePausedState.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <GamePausedState.h>

#include <StatesBuilder.h>

GamePausedState::GamePausedState(StatesBuilder& sb, EventObserver& observer) :
    State(sb),
    eventObserver(observer) {}

ControllerPtr GamePausedState::getController() {
    return ControllerPtr(new StartController(eventObserver));
}

StatePtr GamePausedState::transitionToExit() {
    return statesBuilder.getExitState();
}

StatePtr GamePausedState::transitionToGameInProgress() {
    return statesBuilder.getGameInProgressState();
}
