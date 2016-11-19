#ifndef PILE_H
#define PILE_H

#include <Card.h>

#include <vector>

typedef std::vector<const Card*>::const_iterator PileIterator;

class Pile {
private:
    std::vector<const Card*> cards;

public:
    Pile() { }

    void add(const Card* c);
    void add(const std::vector<const Card*>& cards);
    bool hasCards() const;
    int getNumberOfCards() const;
    const Card* showTopCard() const;
    const Pile showLastCards(int n) const;
    const Card* removeTopCard();
    PileIterator begin() const;
    PileIterator end() const;
};

#endif
