/*
 * TestDeck.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <TestDeck.h>

TestDeck::TestDeck() {
    int numberOfCards = NUM_CARDS_PER_SUIT * NUM_SUITS;
    for (int i = 0; i < numberOfCards; ++i) {
        cards.push_back(Card(i, i%2, 0, 0));
        remainingCardIds.push_back(i);
    }
}

DeckPtr TestDeck::newDeck() const {
    return DeckPtr(new TestDeck());
}

DeckType TestDeck::getDeckType() const {
    return TEST_DECK;
}

int TestDeck::getNumCardsPerSuit() const {
    return 2;
}

int TestDeck::getNumSuits() const {
    return NUM_SUITS;
}

