/*
 * FrenchDeck.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <FrenchDeck.h>

FrenchDeck::FrenchDeck() {
    int numberOfCards = NUM_CARDS_PER_SUIT * NUM_SUITS;
    for (int i = 0; i < numberOfCards; ++i) {
        cards.push_back(Card(i, i%2 + 1));
        remainingCardIds.push_back(i);
    }
}

DeckPtr FrenchDeck::newDeck() const {
    return DeckPtr(new FrenchDeck());
}

DeckType FrenchDeck::getDeckType() const {
    return FRENCH_DECK;
}

int FrenchDeck::getNumCardsPerSuit() const {
    return 2;
}

int FrenchDeck::getNumSuits() const {
    return NUM_SUITS;
}
