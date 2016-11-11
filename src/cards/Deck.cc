#include <Deck.h>

#include <assert.h>

Deck::Deck() {
    int numberOfCards = NUM_CARDS_PER_SUIT * NUM_SUITS;
    for (int i = 0; i < numberOfCards; ++i) {
        cards.push_back(Card(i, i%2 + 1));
        remainingCardIds.push_back(i);
    }
}

const Card* Deck::removeTop() {
    assert(hasCards());
    int cardId = remainingCardIds.back();
    remainingCardIds.pop_back();
    return &cards[cardId];
}

bool Deck::hasCards() {
    return remainingCardIds.size() > 0;
}

int Deck::getNumCardsPerSuit() const {
    return NUM_CARDS_PER_SUIT;
}
int Deck::getNumSuits() const {
    return NUM_SUITS;
}
