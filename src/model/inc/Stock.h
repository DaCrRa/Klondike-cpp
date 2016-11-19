/*
 * Stock.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <Pile.h>
#include <MoveOrigin.h>
#include <StockVisitor.h>

class Stock : public MoveOrigin {
private:
    static const int MAX_CARDS_ALLOWED_TO_MOVE_FROM_WASTE;

    Pile covered;
    Pile waste;

    void transferAllCards(Pile& from, Pile& to);
    void transferCards(Pile& from, Pile& to, int n);
    int stockMovement(Pile& from, Pile& to, int n);
public:
    void addToCovered(const Card* c);
    int moveForward();
    void moveBackward(int numCards);
    int getNumCardsAvailableToMove() const;
    bool hasCoveredCards() const;
    bool hasCards() const;
    void accept(MoveOriginVisitor* v);
    const Pile showAvailableCards(int n) const;
    Pile removeCards(int n);
    void recoverCard(const Card* c);
    void acceptStockVisitor(StockVisitor* visitor);
};

#endif
