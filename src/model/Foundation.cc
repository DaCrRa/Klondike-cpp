/*
 * Foundation.cc
 *
 *  Created on: 2 Apr 2016
 *      Author: dancre
 */

#include <Foundation.h>

#include <assert.h>

void Foundation::add(const Card* c) {
    assert(cardCanBeAdded(c));
    pile.add(c);
}

void Foundation::recoverCard(const Card* c) {
    pile.add(c);
}

bool Foundation::cardCanBeAdded(const Card* c) {
    if (!pile.hasCards()) {
        return c->getRank() == 0;
    } else {
        return c->hasSameSuit(pile.top()) && c->compareRank(pile.top()) == 1;
    }
}

bool Foundation::isCompleted() const {
    return pile.getNumberOfCards() == NUM_CARDS_TO_COMPLETE;
}

int Foundation::getNumCards() const {
    return pile.getNumberOfCards();
}

const Card* Foundation::top() const {
    return pile.top();
}

bool Foundation::hasCardAvailable() const {
    return pile.hasCards();
}

const Card* Foundation::showAvailableCard() const {
    return pile.top();
}

const Card* Foundation::removeAvailableCard() {
    return pile.removeTop();
}

void Foundation::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void Foundation::accept(MoveDestVisitor* v) {
    v->visit(this);
}

void Foundation::acceptFoundationVisitor(FoundationVisitor* v) {
    for (const Card* c : pile) {
        v->visitCard(c);
    }
    v->allCardsVisited();
}
