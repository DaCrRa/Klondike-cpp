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
	void add(const Card* c);
	bool accept(const Card* c);
	int getNumCoveredCards() const;
	PileIterator uncoveredCardsBegin() const;
	PileIterator uncoveredCardsEnd() const;
};

#endif
