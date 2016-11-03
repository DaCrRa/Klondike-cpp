/*
 * GamePausedState.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <GamePausedState.h>

#include <StatesBuilder.h>

GamePausedState::GamePausedState(StatesBuilder& sb,
                                 EventObserver& observer,
                                 GameStatePtr gs) :
    State(sb),
    eventObserver(observer),
    gameState(gs) {}

ControllerPtr GamePausedState::getController() {
    return ControllerPtr(new StartController(gameState, eventObserver));
}

StatePtr GamePausedState::transitionToExit() {
    return statesBuilder.getExitState();
}

StatePtr GamePausedState::transitionToGameInProgress() {
    return statesBuilder.getGameInProgressState();
}
