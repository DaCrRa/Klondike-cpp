#ifndef CARD_H
#define CARD_H

class Card {

private:
    int cardId;
    int rank;

public:
    Card(int cardId, int rank);

    int getCardId() const;

    int getRank() const;

    bool hasSameSuit(const Card* c) const;

    bool hasSameColor(const Card* c) const;

    int compareRank(const Card* c) const;
};

#endif
