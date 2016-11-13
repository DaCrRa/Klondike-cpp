/*
 * SpanishDeck.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <SpanishDeck.h>

SpanishDeck::SpanishDeck() {
    int numberOfCards = NUM_CARDS_PER_SUIT * NUM_SUITS;
    for (int i = 0; i < numberOfCards; ++i) {
        cards.push_back(Card(i, i%2 + 1));
        remainingCardIds.push_back(i);
    }
}

DeckType SpanishDeck::getDeckType() const {
	return SPANISH_DECK;
}

int SpanishDeck::getNumCardsPerSuit() const {
    return 2;
}

int SpanishDeck::getNumSuits() const {
    return NUM_SUITS;
}
