/*
 * DeckFactory.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <AbstractDeckFactory.h>

#include <algorithm>
#include <assert.h>

AbstractDeckFactory::AbstractDeckFactory(std::vector<std::shared_ptr<Deck> > d) {
    for (std::shared_ptr<Deck> deck : d) {
        deckTypes.push_back(deck->getDeckType());
        decks[deck->getDeckType()] = deck;
        selectedDeckType = deck->getDeckType();
    }
}

void AbstractDeckFactory::setSelectedDeck(DeckType type) {
    assert(std::find(deckTypes.begin(), deckTypes.end(), type) != deckTypes.end());
    selectedDeckType = type;
}

int AbstractDeckFactory::getNumberOfAvailableDecks() {
    return decks.size();
}

std::vector<DeckType> AbstractDeckFactory::getDeckTypes() {
    return deckTypes;
}

DeckPtr AbstractDeckFactory::getDeck() {
    return decks[selectedDeckType]->newDeck();
}

DeckType AbstractDeckFactory::getDeckType() {
    return selectedDeckType;
}
