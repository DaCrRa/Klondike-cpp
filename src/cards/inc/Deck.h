#ifndef _DECK_H
#define _DECK_H

#include <Card.h>
#include <DeckTypes.h>

#include <vector>

class Deck {
protected:
    std::vector<Card> cards;
    std::vector<int> remainingCardIds;
public:
    const Card* removeTop();
    const Card* removeCard(int cardId);
    bool hasCards();
    virtual DeckType getDeckType() const = 0;
    virtual int getNumCardsPerSuit() const = 0;
    virtual int getNumSuits() const = 0;
    virtual ~Deck() {}
};

#endif
