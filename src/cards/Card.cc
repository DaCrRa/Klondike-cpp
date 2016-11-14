#include <Card.h>

Card::Card(int id, int r, int s, int c) :
    cardId(id),
    rank(r),
    suit(s),
    color(c)
{}

int Card::getCardId() const {
    return cardId;
}

int Card::getRank() const {
    return rank;
}

bool Card::hasSameSuit(const Card* c) const {
    return suit == c->suit;
}

bool Card::hasSameColor(const Card* c) const {
    return color == c->color;
}

int Card::compareRank(const Card* c) const {
    return this->rank - c->rank;
}
