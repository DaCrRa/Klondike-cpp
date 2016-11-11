#include <Card.h>

#include <vector>

class Deck {
private:
    // 52 cards
    static const int NUM_CARDS_PER_SUIT = 2;
    static const int NUM_SUITS = 26;

    std::vector<Card> cards;
    std::vector<int> remainingCardIds;
public:
    Deck();
    const Card* removeTop();
    bool hasCards();
    int getNumCardsPerSuit() const;
    int getNumSuits() const;
};
