/*
 * Foundation.cc
 *
 *  Created on: 2 Apr 2016
 *      Author: dancre
 */

#include <Foundation.h>

#include <assert.h>
#include <algorithm>

const int Foundation::MAX_CARDS_ALLOWED_TO_MOVE_FROM_FOUNDATION = 1;

void Foundation::addCards(Pile& cards) {
    assert(cardsCanBeAdded(cards));
    pile.add(cards.removeTopCard());
}

void Foundation::recoverCard(const Card* c) {
    pile.add(c);
}

bool Foundation::cardsCanBeAdded(const Pile& cards) const {
    if (cards.getNumberOfCards() != 1) {
        return false;
    }
    const Card* c = *(cards.begin());
    if (!pile.hasCards()) {
        return c->getRank() == 0;
    } else {
        return c->hasSameSuit(pile.showTopCard()) && c->compareRank(pile.showTopCard()) == 1;
    }
}

bool Foundation::isCompleted() const {
    return pile.getNumberOfCards() == NUM_CARDS_TO_COMPLETE;
}

int Foundation::getNumCards() const {
    return pile.getNumberOfCards();
}

const Card* Foundation::top() const {
    return pile.showTopCard();
}

int Foundation::getNumCardsAvailableToMove() const {
    return std::min(getNumCards(), Foundation::MAX_CARDS_ALLOWED_TO_MOVE_FROM_FOUNDATION);
}

const Pile Foundation::showAvailableCards(int n) const {
    assert(n <= getNumCardsAvailableToMove());
    return pile.showLastCards(n);
}

Pile Foundation::removeCards(int n) {
    assert(n <= getNumCardsAvailableToMove());
    return pile.removeLastCards(n);
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
