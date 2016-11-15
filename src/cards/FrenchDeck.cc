/*
 * FrenchDeck.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <FrenchDeck.h>

FrenchDeck::FrenchDeck() {
    int cardSequenceNumber = 0;
    for (int suit = 0; suit < NUM_SUITS; ++suit) {
        int color = suit % NUM_COLORS;
        for (int rank = 0; rank < NUM_CARDS_PER_SUIT; ++rank) {
            cards.push_back(Card(cardSequenceNumber, rank, suit, color));
            remainingCardIds.push_back(cardSequenceNumber);
            ++cardSequenceNumber;
        }
    }
}

DeckPtr FrenchDeck::newDeck() const {
    return DeckPtr(new FrenchDeck());
}

DeckType FrenchDeck::getDeckType() const {
    return FRENCH_DECK;
}

int FrenchDeck::getNumCardsPerSuit() const {
    return NUM_CARDS_PER_SUIT;
}

int FrenchDeck::getNumSuits() const {
    return NUM_SUITS;
}
