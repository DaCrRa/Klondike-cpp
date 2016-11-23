/*
 * FoundationImpl.cc
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#include <FoundationImpl.h>


bool FoundationImpl::isCompleted() const {
    return faceUpCards.getNumberOfCards() == NUM_CARDS_TO_COMPLETE;
}

int FoundationImpl::getNumCards() const {
    return faceUpCards.getNumberOfCards();
}

const Card* FoundationImpl::top() const {
    return faceUpCards.showTopCard();
}

void FoundationImpl::acceptFoundationVisitor(FoundationVisitor* v) {
    for (const Card* c : faceUpCards) {
        v->visitCard(c);
    }
    v->allCardsVisited();
}

bool FoundationImpl::cardMeetsFirstCardCondition(const Card* card) const {
    return card->getRank() == 0;
}

bool FoundationImpl::addCardCondition(const Card* referenceCard, const Card* cardToAdd) const {
    return cardToAdd->hasSameSuit(referenceCard) &&
           cardToAdd->compareRank(referenceCard) == 1;
}

int FoundationImpl::getNumCardsAvailableToMove() const {
    return std::min(getNumCards(), Foundation::MAX_CARDS_ALLOWED_TO_MOVE_FROM_FOUNDATION);
}

void FoundationImpl::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void FoundationImpl::accept(MoveDestVisitor* v) {
    v->visit(this);
}
