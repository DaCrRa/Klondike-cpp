#include <Deck.h>

#include <assert.h>

Deck::Deck() : remainingCards(NUM_CARDS) {
   for (int i = 0; i < NUM_CARDS; ++i) {
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
