/*
 * GameCompletedState.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#include <GameCompletedState.h>
#include <AppStatesBuilder.h>

GameCompletedState::GameCompletedState(AppStatesBuilder& sb,
                                       EventObserver& o,
                                       std::shared_ptr<BestScoresController>& bsc) :
    AppState(sb),
    eventObserver(o),
    bestScoresController(bsc) {}

ControllerPtr GameCompletedState::getController() {
    return ControllerPtr(bestScoresController);
}

AppStatePtr GameCompletedState::transitionToNoGameInProgress() {
    return statesBuilder.getInitialState();
}
