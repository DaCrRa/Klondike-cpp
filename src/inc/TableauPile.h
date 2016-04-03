#ifndef TABLEAUPILE_H
#define TABLEAUPILE_H

#include <Pile.h>

class TableauPile {
private:
	Pile coveredCards;
	Pile uncoveredCards;
public:
	void turnUp();
	void addToCovered(const Card* c);
	void add(Card* c);
	bool accept(Card* c);
};

#endif
