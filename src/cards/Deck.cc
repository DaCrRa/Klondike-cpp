#include <Deck.h>

#include <assert.h>

#include <algorithm>

const Card* Deck::removeRandomCard() {
    assert(hasCards());

    return removeCard(remainingCardIds[std::rand() % remainingCardIds.size()]);
}

const Card* Deck::removeCard(int cardId) {
    assert(hasCards());

    remainingCardIds.erase(std::find(remainingCardIds.begin(),
                                     remainingCardIds.end(),
                                     cardId));
    return &cards[cardId];
}

bool Deck::hasCards() {
    return remainingCardIds.size() > 0;
}
