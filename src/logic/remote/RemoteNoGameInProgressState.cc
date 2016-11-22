/*
 * RemoteNoGameInProgressState.cc
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#include <RemoteNoGameInProgressState.h>
#include <RemoteStartController.h>

RemoteNoGameInProgressState::RemoteNoGameInProgressState(AppStatesBuilder& sb,
        std::shared_ptr<AbstractDeckFactory> factory,
        GameSessionStarter& starter,
        EventObserver& eventObserver,
        GameStatePtr gameState) :
    NoGameInProgressState(sb, factory, starter, eventObserver, gameState) {}

ControllerPtr RemoteNoGameInProgressState::getController() {
    return ControllerPtr(new RemoteStartController(deckFactory, gameSessionStarter, gameState, eventObserver));
}
