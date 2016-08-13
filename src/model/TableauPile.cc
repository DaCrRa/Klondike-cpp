/*
 * TableauPile.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */
#include <TableauPile.h>

#include <assert.h>

void TableauPile::turnUp() {
    assert(!uncoveredCards.hasCards());
    uncoveredCards.add(coveredCards.removeTop());
}

void TableauPile::addToCovered(const Card* c) {
    //TODO Assert we are in initial state of Klondike
    coveredCards.add(c);
}

bool TableauPile::accept(const Card* c) {
    if (uncoveredCards.hasCards()) {
        return !c->hasSameColor(uncoveredCards.top()) && c->compareRank(uncoveredCards.top()) == -1;
    } else {
        return !coveredCards.hasCards() && c->getRank() == 12;
    }
}

void TableauPile::add(const Card* c) {
    assert(accept(c));
    uncoveredCards.add(c);
}

int TableauPile::getNumCoveredCards() const {
    return coveredCards.getNumberOfCards();
}

PileIterator TableauPile::uncoveredCardsBegin() const {
    return uncoveredCards.begin();
}

PileIterator TableauPile::uncoveredCardsEnd() const {
    return uncoveredCards.end();
}

bool TableauPile::hasCardAvailable() const {
    return uncoveredCards.hasCards();
}

const Card* TableauPile::showAvailableCard() const {
    return uncoveredCards.top();
}

const Card* TableauPile::removeAvailableCard() {
    const Card* removedCard = uncoveredCards.removeTop();
    if (!uncoveredCards.hasCards() && coveredCards.hasCards()) {
        uncoveredCards.add(coveredCards.removeTop());
    }
    return removedCard;
}

void TableauPile::accept(MoveOriginVisitor* v) {
    v->visit(this);
}
