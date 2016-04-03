#ifndef PILE_H
#define PILE_H

#include <Card.h>

#include <vector>

class Pile {
private:
	std::vector<const Card*> cards;

public:
	Pile() { }

	void add(const Card* c);
	void add(const std::vector<const Card*>& cards);
	bool hasCards();
	int getNumberOfCards();
	const Card* top();
	const Card* removeTop();
};

#endif
