#ifndef CARD_H
#define CARD_H

#include <CardVisitor.h>

class Card {

private:
    int cardId;

    int rank;
    int suit;
    int color;

public:
    Card(int cardId, int rank, int suit, int color);

    int getCardId() const;

    int getRank() const;

    bool hasSameSuit(const Card* c) const;

    bool hasSameColor(const Card* c) const;

    int compareRank(const Card* c) const;

    void acceptCardVisitor(const CardVisitor& visitor) const;
};

#endif
