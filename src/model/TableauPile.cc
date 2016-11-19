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
    uncoveredCards.add(coveredCards.removeTopCard());
}

void TableauPile::turnDownCard() {
    coveredCards.add(uncoveredCards.removeTopCard());
}

bool TableauPile::cardCanBeTurnUp() {
    return !uncoveredCards.hasCards() && coveredCards.hasCards();
}

void TableauPile::addToCovered(const Card* c) {
    coveredCards.add(c);
}

bool TableauPile::cardsCanBeAdded(const Pile& cards) const {
    const Card* c = *(cards.begin());
    if (uncoveredCards.hasCards()) {
        return !c->hasSameColor(uncoveredCards.showTopCard()) && c->compareRank(uncoveredCards.showTopCard()) == -1;
    } else {
        return !coveredCards.hasCards() && c->getRank() == MAX_RANK_ACCEPTED;
    }
}

void TableauPile::addCards(Pile& cards) {
    assert(cardsCanBeAdded(cards));
    for (const Card* c : cards) {
        uncoveredCards.add(c);
    }
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

int TableauPile::getNumCardsAvailableToMove() const {
    return uncoveredCards.getNumberOfCards();
}

const Card* TableauPile::showAvailableCard() const {
    return uncoveredCards.showTopCard();
}

const Card* TableauPile::removeAvailableCard() {
    return uncoveredCards.removeTopCard();
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
    for (const Card* c : uncoveredCards) {
        visitor->visitUncoveredCard(c);
    }
    visitor->allUncoveredCardsVisited();
}
