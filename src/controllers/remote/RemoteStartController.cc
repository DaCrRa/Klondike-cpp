/*
 * RemoteStartController.cc
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#include <RemoteStartController.h>

#include <KlondikeProxy.h>

RemoteStartController::RemoteStartController(std::shared_ptr<AbstractDeckFactory> factory,
        GameSessionStarter& starter,
        GameStatePtr state,
        EventObserver& observer) :
    StartController(factory, starter, state, observer) {}

std::shared_ptr<Klondike> RemoteStartController::instantiateKlondike() {
    return std::shared_ptr<Klondike>(new KlondikeProxy("klondike.host.name.org",
                                     deckFactory->getDeckType()));
}
