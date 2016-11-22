/*
 * LocalStartController.cc
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#include <LocalStartController.h>

#include <KlondikeImpl.h>

LocalStartController::LocalStartController(std::shared_ptr<AbstractDeckFactory> factory,
        GameSessionStarter& starter,
        GameStatePtr state,
        EventObserver& observer) :
    StartController(factory, starter, state, observer) {}

std::shared_ptr<Klondike> LocalStartController::instantiateKlondike() {
    return std::shared_ptr<Klondike>(new KlondikeImpl(deckFactory->getDeck()));
}
