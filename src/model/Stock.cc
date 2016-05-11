/*
 * Stock.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Stock.h>

#include <algorithm>
#include <assert.h>

void Stock::addToCovered(const Card* c) {
	// TODO assert we are in initial state
	covered.add(c);
}

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
	while (waste.hasCards()) {
		covered.add(waste.removeTop());
	}
}

bool Stock::hasCardAvailable() const {
	return waste.hasCards();
}

const Card* Stock::showAvailableCard() const {
	assert(hasCardAvailable());
	return waste.top();
}

const Card* Stock::removeAvailableCard() {
	assert(hasCardAvailable());
    return waste.removeTop();
}

bool Stock::hasCoveredCards() const {
	return covered.hasCards();
}

bool Stock::hasCards() const {
	return hasCoveredCards() || hasCardAvailable();
}
