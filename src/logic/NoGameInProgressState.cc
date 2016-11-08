/*
 * GamePausedState.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <NoGameInProgress.h>

#include <AppStatesBuilder.h>

NoGameInProgressState::NoGameInProgressState(AppStatesBuilder& sb,
        std::shared_ptr<Klondike>& g,
        std::shared_ptr<GameActionHistoryController>& historyController,
        GameActionControllerHolder& holder,
        EventObserver& eventObserver,
        GameStatePtr gameStates) :
    AppState(sb),
    game(g),
    historyController(historyController),
    holder(holder),
    eventObserver(eventObserver),
    gameState(gameStates) {}

ControllerPtr NoGameInProgressState::getController() {
    return ControllerPtr(new StartController(game, historyController, holder, gameState, eventObserver));
}

AppStatePtr NoGameInProgressState::transitionToExit() {
    return statesBuilder.getExitState();
}

AppStatePtr NoGameInProgressState::transitionToGameInProgress() {
    return statesBuilder.getGameInProgressState();
}

AppStatePtr NoGameInProgressState::transitionToSavingGame() {
    return statesBuilder.getSavingGameState();
}

AppStatePtr NoGameInProgressState::transitionToLoadingGame() {
    return statesBuilder.getLoadingGameState();
}
