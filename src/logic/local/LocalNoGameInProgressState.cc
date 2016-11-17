/*
 * LocalNoGameInProgressState.cc
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#include <LocalNoGameInProgressState.h>

#include <LocalStartController.h>

LocalNoGameInProgressState::LocalNoGameInProgressState(AppStatesBuilder& sb,
        std::shared_ptr<AbstractDeckFactory> factory,
        GameSessionStarter& starter,
        EventObserver& eventObserver,
        GameStatePtr gameState) :
    NoGameInProgressState(sb, factory, starter, eventObserver, gameState) {}

ControllerPtr LocalNoGameInProgressState::getController() {
    return ControllerPtr(new LocalStartController(deckFactory, gameSessionStarter, gameState, eventObserver));
}
