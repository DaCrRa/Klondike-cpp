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

#include <memory>

class Stock;
typedef std::shared_ptr<Stock> StockPtr;

class Stock : virtual public MoveOrigin {

public:
    virtual int moveForward() = 0;
    virtual void moveBackward(int numCards) = 0;
    virtual int getNumCardsAvailableToMove() const = 0;
    virtual bool hasCoveredCards() const = 0;
    virtual bool hasCards() const = 0;
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual void acceptStockVisitor(StockVisitor* visitor) = 0;
    virtual ~Stock() {}
};

#endif
