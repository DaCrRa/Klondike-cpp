/*
 * SpanishDeck.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <SpanishDeck.h>

SpanishDeck::SpanishDeck() {
    int numberOfCards = NUM_CARDS_PER_SUIT * NUM_SUITS;
    int cardSequenceNumber = 0;
    for (int suit = 0; suit < NUM_SUITS; ++suit) {
        for (int rank = 0; rank < NUM_CARDS_PER_SUIT; ++rank) {
            cards.push_back(Card(cardSequenceNumber, rank, suit, suit));
            remainingCardIds.push_back(cardSequenceNumber);
            ++cardSequenceNumber;
        }
    }
}

DeckPtr SpanishDeck::newDeck() const {
    return DeckPtr(new SpanishDeck());
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
