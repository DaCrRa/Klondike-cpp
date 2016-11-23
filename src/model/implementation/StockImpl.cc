/*
 * StockImpl.cc
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#include <StockImpl.h>

#include <algorithm>
#include <assert.h>

const int StockImpl::MAX_CARDS_ALLOWED_TO_MOVE_FROM_WASTE = 1;

void StockImpl::addToCovered(const Card* c) {
    // TODO assert we are in initial state
    stock.add(c);
}

void StockImpl::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

int StockImpl::moveForward() {
    return stockMovement(stock, faceUpCards, 3); // TODO Magic number!
}

void StockImpl::moveBackward(int numCards) {
    stockMovement(faceUpCards, stock, numCards);
}

int StockImpl::stockMovement(Pile& from, Pile& to, int n) {
    if (from.hasCards()) {
        int cardsToMove = std::min(n, from.getNumberOfCards());
        transferCards(from, to, cardsToMove);
        return cardsToMove;
    } else {
        transferAllCards(to, from);
        return from.getNumberOfCards();
    }
}

void StockImpl::transferAllCards(Pile& from, Pile& to) {
    assert(!to.hasCards());
    transferCards(from, to, from.getNumberOfCards());
}

void StockImpl::transferCards(Pile& from, Pile& to, int n) {
    assert(from.getNumberOfCards() >= n);
    for (int i = 0; i < n; i++) {
        to.add(from.removeTopCard());
    }
}

int StockImpl::getNumCardsAvailableToMove() const {
    return std::min(faceUpCards.getNumberOfCards(), StockImpl::MAX_CARDS_ALLOWED_TO_MOVE_FROM_WASTE);
}

bool StockImpl::hasCoveredCards() const {
    return stock.hasCards();
}

bool StockImpl::hasCards() const {
    return ( stock.getNumberOfCards() + faceUpCards.getNumberOfCards() ) > 0;
}

void StockImpl::acceptStockVisitor(StockVisitor* visitor) {
    for (const Card* c : stock) {
        visitor->visitCoveredCard(c);
    }
    visitor->allCoveredCardsVisited();
    for (const Card* c : faceUpCards) {
        visitor->visitWasteCard(c);
    }
    visitor->allWasteCardsVisited();
}
