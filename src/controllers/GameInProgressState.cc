/*
 * GameInProgress.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <GameInProgressState.h>

#include <StatesBuilder.h>

GameInProgressState::GameInProgressState(StatesBuilder& sb,
        EventObserver& observer,
        std::shared_ptr<Klondike>& g,
        std::shared_ptr<GameActionHistoryController>& h) :
    State(sb),
    eventObserver(observer),
    game(g),
    historyController(h) {}

ControllerPtr GameInProgressState::getController() {
    return ControllerPtr(new UserGameActionController(eventObserver, game, historyController));
}

StatePtr GameInProgressState::transitionToGamePaused() {
    return statesBuilder.getInitialState();
}

StatePtr GameInProgressState::transitionToGameCompleted() {
    return statesBuilder.getGameCompletedState();
}
