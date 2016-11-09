#include <Card.h>

Card::Card(int id, int r) :
    cardId(id),
    rank(r)
{
}

int Card::getCardId() const {
    return cardId;
}

int Card::getRank() const {
    return rank;
}

bool Card::hasSameSuit(const Card* c) const {
    //TODO
    return true;
}

bool Card::hasSameColor(const Card* c) const {
    //TODO
    return false;
}

int Card::compareRank(const Card* c) const {
    return this->rank - c->rank;
}
