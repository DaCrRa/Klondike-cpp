/*
 * SpanishDeck.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_INC_SPANISHDECK_H_
#define SRC_CARDS_INC_SPANISHDECK_H_

#include <Deck.h>

class SpanishDeck: public Deck {
private:
    int NUM_CARDS_PER_SUIT = 13;
    int NUM_SUITS = 4;
public:
    SpanishDeck();
    DeckType getDeckType() const;
    int getNumCardsPerSuit() const;
    int getNumSuits() const;
};

#endif /* SRC_CARDS_INC_SPANISHDECK_H_ */
