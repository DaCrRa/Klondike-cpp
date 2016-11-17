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

void LocalStartController::start(std::shared_ptr<GameActionController> gameActionController) {
    std::shared_ptr<Klondike> game(new KlondikeImpl(deckFactory->getDeck()));
    game->initialize();
    sessionStarter.startSession(game, gameActionController);
    eventObserver.gameStarted();
}
