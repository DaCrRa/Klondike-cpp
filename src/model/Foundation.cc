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

void Foundation::recoverCard(const Card* c) {
    faceUpCards.add(c);
}

bool Foundation::cardMeetsFirstCardCondition(const Card* card) const {
    return card->getRank() == 0;
}

bool Foundation::addCardCondition(const Card* referenceCard, const Card* cardToAdd) const {
    return cardToAdd->hasSameSuit(referenceCard) &&
           cardToAdd->compareRank(referenceCard) == 1;
}

bool Foundation::isCompleted() const {
    return faceUpCards.getNumberOfCards() == NUM_CARDS_TO_COMPLETE;
}

int Foundation::getNumCards() const {
    return faceUpCards.getNumberOfCards();
}

const Card* Foundation::top() const {
    return faceUpCards.showTopCard();
}

int Foundation::getNumCardsAvailableToMove() const {
    return std::min(getNumCards(), Foundation::MAX_CARDS_ALLOWED_TO_MOVE_FROM_FOUNDATION);
}

const Pile Foundation::showAvailableCards(int n) const {
    assert(n <= getNumCardsAvailableToMove());
    return faceUpCards.showLastCards(n);
}

Pile Foundation::removeCards(int n) {
    assert(n <= getNumCardsAvailableToMove());
    return faceUpCards.removeLastCards(n);
}

void Foundation::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void Foundation::accept(MoveDestVisitor* v) {
    v->visit(this);
}

void Foundation::acceptFoundationVisitor(FoundationVisitor* v) {
    for (const Card* c : faceUpCards) {
        v->visitCard(c);
    }
    v->allCardsVisited();
}
