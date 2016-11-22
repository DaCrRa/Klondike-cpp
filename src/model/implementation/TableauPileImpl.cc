/*
 * TableauPileImpl.cc
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#include <TableauPileImpl.h>

void TableauPileImpl::turnUpCard() {
    assert(cardCanBeTurnUp());
    faceUpCards.add(coveredCards.removeTopCard());
}

void TableauPileImpl::turnDownCard() {
    coveredCards.add(faceUpCards.removeTopCard());
}

bool TableauPileImpl::cardCanBeTurnUp() {
    return !faceUpCards.hasCards() && coveredCards.hasCards();
}

void TableauPileImpl::addToCovered(const Card* c) {
    coveredCards.add(c);
}

int TableauPileImpl::getNumCoveredCards() const {
    return coveredCards.getNumberOfCards();
}

PileIterator TableauPileImpl::uncoveredCardsBegin() const {
    return faceUpCards.begin();
}

PileIterator TableauPileImpl::uncoveredCardsEnd() const {
    return faceUpCards.end();
}

int TableauPileImpl::getNumCardsAvailableToMove() const {
    return faceUpCards.getNumberOfCards();
}

void TableauPileImpl::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

bool TableauPileImpl::cardMeetsFirstCardCondition(const Card* card) const {
    return card->getRank() == MAX_RANK_ACCEPTED;
}

bool TableauPileImpl::addCardCondition(const Card* referenceCard, const Card* cardToAdd) const {
    return !cardToAdd->hasSameColor(referenceCard) &&
           cardToAdd->compareRank(referenceCard) == -1;
}

void TableauPileImpl::accept(MoveDestVisitor* v) {
    v->visit(this);
}

void TableauPileImpl::acceptTableauPileVisitor(TableauPileVisitor* visitor) {
    for (const Card* c : coveredCards) {
        visitor->visitCoveredCard(c);
    }
    visitor->allCoveredCardsVisited();
    for (const Card* c : faceUpCards) {
        visitor->visitUncoveredCard(c);
    }
    visitor->allUncoveredCardsVisited();
}
