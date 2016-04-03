/*
 * Stock.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Stock.h>

#include <algorithm>
#include <assert.h>

void Stock::move() {
	if (covered.hasCards()) {
		int cardsToMove = std::min(3, covered.getNumberOfCards()); //TODO magic number!
		for (int i = 0; i < cardsToMove; i++) {
			waste.add(covered.removeTop());
		}
	} else {
		rotate();
	}
}

void Stock::rotate() {
	assert(!covered.hasCards());
	for (int i = 0; i < waste.getNumberOfCards(); i++) {
		covered.add(waste.removeTop());
	}
}

bool Stock::hasCardAvailable() {
	return waste.hasCards();
}

const Card* Stock::availableCard() {
	assert(hasCardAvailable());
	return waste.removeTop();
}
