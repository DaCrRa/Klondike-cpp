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
	const Card* top() const;
	const Card* removeTop();
	PileIterator begin() const;
	PileIterator end() const;
};

#endif
