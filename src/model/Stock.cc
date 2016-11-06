/*
 * Stock.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Stock.h>

#include <algorithm>
#include <assert.h>

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
        to.add(from.removeTop());
    }
}

bool Stock::hasCardAvailable() const {
    return waste.hasCards();
}

void Stock::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

const Card* Stock::showAvailableCard() const {
    assert(hasCardAvailable());
    return waste.top();
}

const Card* Stock::removeAvailableCard() {
    assert(hasCardAvailable());
    return waste.removeTop();
}

bool Stock::hasCoveredCards() const {
    return covered.hasCards();
}

bool Stock::hasCards() const {
    return hasCoveredCards() || hasCardAvailable();
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
