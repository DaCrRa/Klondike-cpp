/*
 * StockImpl.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_STOCKIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_STOCKIMPL_H_

#include <Stock.h>
#include <MoveOriginImpl.h>

class StockImpl : public Stock, public MoveOriginImpl {
private:
    Pile stock;
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
    void acceptStockVisitor(StockVisitor* visitor);
};

#endif /* SRC_MODEL_IMPLEMENTATION_INC_STOCKIMPL_H_ */
