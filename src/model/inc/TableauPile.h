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
	bool hasCardAvailable() const;
	const Card* showAvailableCard() const;
	const Card* removeAvailableCard();
	int getNumCoveredCards() const;
	PileIterator uncoveredCardsBegin() const;
	PileIterator uncoveredCardsEnd() const;
};

#endif
