#include <Card.h>

#include <vector>

class Deck {
   private:
      std::vector<Card> cards;
      int remainingCards;

   public:
      static const int NUM_CARDS = 52;

      Deck();

      Card& takeNext();

      bool hasMoreCards();
};
