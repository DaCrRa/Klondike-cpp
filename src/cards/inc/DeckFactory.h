/*
 * DeckFactory.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_INC_DECKFACTORY_H_
#define SRC_CARDS_INC_DECKFACTORY_H_

#include <Deck.h>

#include <memory>

class DeckFactory {
protected:
    std::shared_ptr<Deck> deck;
    DeckFactory(std::shared_ptr<Deck> d) :
        deck(d) {}
public:
    Deck& getDeck();
};

#endif /* SRC_CARDS_INC_DECKFACTORY_H_ */
