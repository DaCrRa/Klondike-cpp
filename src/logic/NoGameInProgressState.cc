/*
 * GamePausedState.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <NoGameInProgress.h>

#include <AppStatesBuilder.h>

NoGameInProgressState::NoGameInProgressState(
    AppStatesBuilder& sb,
    std::shared_ptr<AbstractDeckFactory> factory,
    GameSessionStarter& starter,
    EventObserver& eventObserver,
    GameStatePtr gameStates) :
    AppState(sb),
    deckFactory(factory),
    gameSessionStarter(starter),
    eventObserver(eventObserver),
    gameState(gameStates) {}

ControllerPtr NoGameInProgressState::getController() {
    return ControllerPtr(new StartController(deckFactory, gameSessionStarter, gameState, eventObserver));
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
    return statesBuilder.getLoadingGameState(shared_from_this());
}
