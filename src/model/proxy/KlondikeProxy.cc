/*
 * KlondikeProxy.cc
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#include <KlondikeProxy.h>
#include <StockProxy.h>
#include <FoundationProxy.h>

#include <iostream>

KlondikeProxy::KlondikeProxy(std::string h, DeckType dt) :
    gameId(0),
    host(h) {
    deckType = dt;
}

void KlondikeProxy::initialize() {
    std::cout << "POST http://" << host << "/initialize/" << deckType << std::endl;
    // Get from the server a JSON with game id and all game elements ids:
    // { gameId:"1", stock:"s", foundation:"A", foundation:"B", tableauPile:"1"}
    // Deserialize the JSON and instantiate proxies...
    int gameId = 1;
    stock = StockPtr(new StockProxy(host, gameId, 's'));
    foundations.push_back(FoundationPtr(new FoundationProxy(host, gameId, 'A')));
}

void KlondikeProxy::initialize(KlondikeInitParameters& params) {
    std::cout << "POST http://" << host << "/initialize/" << deckType << std::endl;
    std::cout << "Serialize init parameters in request body" << std::endl;
    // Get from the server a JSON with game id and all game elements ids:
    // { gameId:"1", stock:"s", foundation:"A", foundation:"B", tableauPile:"1"}
    // Deserialize the JSON and instantiate proxies...
    gameId = 1;
    stock = StockPtr(new StockProxy(host, gameId, 's'));
    foundations.push_back(FoundationPtr(new FoundationProxy(host, gameId, 'A')));
}

bool KlondikeProxy::isCompleted() {
    std::cout << "GET http://" << host << "/klondike/" << gameId << "/isCompleted" << std::endl;
    std::cout << "Deserialize boolean" << std::endl;
    return false;
}

