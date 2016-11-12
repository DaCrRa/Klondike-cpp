#include <Deck.h>

#include <assert.h>

#include <algorithm>

const Card* Deck::removeTop() {
    assert(hasCards());
    int cardId = remainingCardIds.back();
    remainingCardIds.pop_back();
    return &cards[cardId];
}

const Card* Deck::removeCard(int cardId) {
    remainingCardIds.erase(std::find(remainingCardIds.begin(),
                                     remainingCardIds.end(),
                                     cardId));
    return &cards[cardId];
}

bool Deck::hasCards() {
    return remainingCardIds.size() > 0;
}
