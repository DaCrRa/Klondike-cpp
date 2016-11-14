/*
 * FrenchDeck.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_INC_FRENCHDECK_H_
#define SRC_CARDS_INC_FRENCHDECK_H_

#include <Deck.h>

class FrenchDeck: public Deck {
private:
    const int NUM_CARDS_PER_SUIT = 13;
    const int NUM_SUITS = 4;
    const int NUM_COLORS = 2;
public:
    FrenchDeck();
    DeckPtr newDeck() const;
    DeckType getDeckType() const;
    int getNumCardsPerSuit() const;
    int getNumSuits() const;
};

#endif /* SRC_CARDS_INC_FRENCHDECK_H_ */
