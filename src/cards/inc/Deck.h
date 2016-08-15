#include <Card.h>

#include <vector>

class Deck {
private:
    static const int NUM_CARDS_PER_SUIT = 13;
    static const int NUM_SUITS = 4;

    std::vector<Card> cards;
    int remainingCards;
public:
    Deck();
    const Card* removeTop();
    bool hasCards();
    int getNumCardsPerSuit() const;
    int getNumSuits() const;
};
