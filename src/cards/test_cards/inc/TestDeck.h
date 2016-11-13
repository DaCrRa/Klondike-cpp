/*
 * TestDeck.h
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_TEST_CARDS_INC_TESTDECK_H_
#define SRC_CARDS_TEST_CARDS_INC_TESTDECK_H_

#include <Deck.h>

class TestDeck: public Deck {
private:
    int NUM_CARDS_PER_SUIT = 13;
    int NUM_SUITS = 4;
public:
    TestDeck();
    DeckType getDeckType() const;
    int getNumCardsPerSuit() const;
    int getNumSuits() const;
};

#endif /* SRC_CARDS_TEST_CARDS_INC_TESTDECK_H_ */
