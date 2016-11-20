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
    faceUpCards.add(coveredCards.removeTopCard());
}

void TableauPile::turnDownCard() {
    coveredCards.add(faceUpCards.removeTopCard());
}

bool TableauPile::cardCanBeTurnUp() {
    return !faceUpCards.hasCards() && coveredCards.hasCards();
}

void TableauPile::addToCovered(const Card* c) {
    coveredCards.add(c);
}

bool TableauPile::cardMeetsFirstCardCondition(const Card* card) const {
    return !coveredCards.hasCards() && card->getRank() == MAX_RANK_ACCEPTED;
}

bool TableauPile::addCardCondition(const Card* referenceCard, const Card* cardToAdd) const {
    return !cardToAdd->hasSameColor(referenceCard) &&
           cardToAdd->compareRank(referenceCard) == -1;
}

int TableauPile::getNumCoveredCards() const {
    return coveredCards.getNumberOfCards();
}

PileIterator TableauPile::uncoveredCardsBegin() const {
    return faceUpCards.begin();
}

PileIterator TableauPile::uncoveredCardsEnd() const {
    return faceUpCards.end();
}

int TableauPile::getNumCardsAvailableToMove() const {
    return faceUpCards.getNumberOfCards();
}

void TableauPile::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void TableauPile::accept(MoveDestVisitor* v) {
    v->visit(this);
}

void TableauPile::acceptTableauPileVisitor(TableauPileVisitor* visitor) {
    for (const Card* c : coveredCards) {
        visitor->visitCoveredCard(c);
    }
    visitor->allCoveredCardsVisited();
    for (const Card* c : faceUpCards) {
        visitor->visitUncoveredCard(c);
    }
    visitor->allUncoveredCardsVisited();
}
