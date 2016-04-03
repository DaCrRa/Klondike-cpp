/*
 * Foundation.cc
 *
 *  Created on: 2 Apr 2016
 *      Author: dancre
 */

#include <Foundation.h>

#include <assert.h>

void Foundation::add(Card* c) {
	assert(accept(c));
	pile.add(c);
}

bool Foundation::accept(Card* c) {
	if (!pile.hasCards()) {
		return c->getRank() == 1;
	} else {
		return c->hasSameSuit(pile.top()) && c->compareRank(pile.top()) == 1;
	}
}

bool Foundation::isCompleted() {
	return pile.getNumberOfCards() == 12; //TODO magic number
}

