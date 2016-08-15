#include <Deck.h>

#include <assert.h>

Deck::Deck() : remainingCards(NUM_CARDS_PER_SUIT * NUM_SUITS) {
    for (int i = 0; i < remainingCards; ++i) {
        cards.push_back(Card(i%2 + 1));
    }
}

const Card* Deck::removeTop() {
    assert(hasCards());
    return &cards[--remainingCards];
}

bool Deck::hasCards() {
    return remainingCards > 0;
}

int Deck::getNumCardsPerSuit() const {
    return NUM_CARDS_PER_SUIT;
}
int Deck::getNumSuits() const {
    return NUM_SUITS;
}
