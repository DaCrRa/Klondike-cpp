/*
 * GameCompletedState.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#include <GameCompletedState.h>
#include <StatesBuilder.h>

GameCompletedState::GameCompletedState(StatesBuilder& sb,
                                       EventObserver& o,
                                       std::shared_ptr<BestScoresController>& bsc) :
    State(sb),
    eventObserver(o),
    bestScoresController(bsc) {}

ControllerPtr GameCompletedState::getController() {
    return ControllerPtr(bestScoresController);
}

StatePtr GameCompletedState::transitionToGamePaused() {
    return statesBuilder.getInitialState();
}
