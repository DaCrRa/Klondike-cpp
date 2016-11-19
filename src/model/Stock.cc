/*
 * Stock.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Stock.h>

#include <algorithm>
#include <assert.h>

const int Stock::MAX_CARDS_ALLOWED_TO_MOVE_FROM_WASTE = 1;

void Stock::addToCovered(const Card* c) {
    // TODO assert we are in initial state
    covered.add(c);
}

void Stock::recoverCard(const Card* c) {
    waste.add(c);
}

int Stock::moveForward() {
    return stockMovement(covered, waste, 3); // TODO Magic number!
}

void Stock::moveBackward(int numCards) {
    stockMovement(waste, covered, numCards);
}

int Stock::stockMovement(Pile& from, Pile& to, int n) {
    if (from.hasCards()) {
        int cardsToMove = std::min(n, from.getNumberOfCards());
        transferCards(from, to, cardsToMove);
        return cardsToMove;
    } else {
        transferAllCards(to, from);
        return from.getNumberOfCards();
    }
}

void Stock::transferAllCards(Pile& from, Pile& to) {
    assert(!to.hasCards());
    transferCards(from, to, from.getNumberOfCards());
}

void Stock::transferCards(Pile& from, Pile& to, int n) {
    assert(from.getNumberOfCards() >= n);
    for (int i = 0; i < n; i++) {
        to.add(from.removeTopCard());
    }
}

int Stock::getNumCardsAvailableToMove() const {
    return std::min(waste.getNumberOfCards(), Stock::MAX_CARDS_ALLOWED_TO_MOVE_FROM_WASTE);
}

void Stock::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

const Pile Stock::showAvailableCards(int n) const {
    assert(n <= getNumCardsAvailableToMove());
    return waste.showLastCards(n);
}

Pile Stock::removeCards(int n) {
    assert(n <= getNumCardsAvailableToMove());
    return waste.removeLastCards(n);
}

bool Stock::hasCoveredCards() const {
    return covered.hasCards();
}

bool Stock::hasCards() const {
    return ( covered.getNumberOfCards() + waste.getNumberOfCards() ) > 0;
}

void Stock::acceptStockVisitor(StockVisitor* visitor) {
    for (const Card* c : covered) {
        visitor->visitCoveredCard(c);
    }
    visitor->allCoveredCardsVisited();
    for (const Card* c : waste) {
        visitor->visitWasteCard(c);
    }
    visitor->allWasteCardsVisited();
}
