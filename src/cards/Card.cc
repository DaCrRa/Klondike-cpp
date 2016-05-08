#include <Card.h>

Card::Card(int r) :
   rank(r)
{
}

int Card::getRank() const {
	return rank;
}

bool Card::hasSameSuit(const Card* c) const {
	//TODO
	return false;
}

bool Card::hasSameColor(const Card* c) const {
	//TODO
	return false;
}

int Card::compareRank(const Card* c) const {
	return this->rank - c->rank;
}
