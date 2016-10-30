/*
 * TableauPile.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */
#include <TableauPile.h>

#include <assert.h>

void TableauPile::turnUpCard() {
    assert(cardCanBeTurnUp());
    uncoveredCards.add(coveredCards.removeTop());
}

bool TableauPile::cardCanBeTurnUp() {
    return !uncoveredCards.hasCards() && coveredCards.hasCards();
}

void TableauPile::addToCovered(const Card* c) {
    //TODO Assert we are in initial state of Klondike
    coveredCards.add(c);
}

bool TableauPile::cardCanBeAdded(const Card* c) {
    if (uncoveredCards.hasCards()) {
        return !c->hasSameColor(uncoveredCards.top()) && c->compareRank(uncoveredCards.top()) == -1;
    } else {
        return !coveredCards.hasCards() && c->getRank() == MAX_RANK_ACCEPTED;
    }
}

void TableauPile::add(const Card* c) {
    assert(cardCanBeAdded(c));
    uncoveredCards.add(c);
}

void TableauPile::recoverCard(const Card* c) {
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
    return uncoveredCards.removeTop();
}

void TableauPile::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void TableauPile::accept(MoveDestVisitor* v) {
    v->visit(this);
}
