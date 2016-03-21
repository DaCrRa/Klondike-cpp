#include <Deck.h>

#include <assert.h>

Deck::Deck() : remainingCards(NUM_CARDS) {
   for (int i = 0; i < NUM_CARDS; ++i) {
      cards.push_back(Card(i));
   }
}

Card& Deck::takeNext() {
   assert(hasMoreCards());
   return cards[--remainingCards];
}

bool Deck::hasMoreCards() {
   return remainingCards > 0;
}
