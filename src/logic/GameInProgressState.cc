/*
 * GameInProgress.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <GameInProgressState.h>

#include <AppStatesBuilder.h>

GameInProgressState::GameInProgressState(AppStatesBuilder& sb,
        EventObserver& observer,
        std::shared_ptr<Klondike>& g,
        std::shared_ptr<GameActionHistoryController>& h) :
    AppState(sb),
    eventObserver(observer),
    game(g),
    historyController(h) {}

ControllerPtr GameInProgressState::getController() {
    return ControllerPtr(new UserGameActionController(eventObserver, game, historyController));
}

AppStatePtr GameInProgressState::transitionToNoGameInProgress() {
    return statesBuilder.getPausedState();
}

AppStatePtr GameInProgressState::transitionToGameCompleted() {
    return statesBuilder.getGameCompletedState();
}
