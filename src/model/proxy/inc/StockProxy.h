/*
 * StockProxy.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_STOCKPROXY_H_
#define SRC_MODEL_PROXY_INC_STOCKPROXY_H_

#include <Stock.h>
#include <MoveOriginProxy.h>

class StockProxy : public Stock, public MoveOriginProxy {
public:
    StockProxy(const std::string& h, int id, char elementId) :
        MoveOriginProxy(h, id, elementId),
        GameElementProxy(h, id, elementId) {}
    int getNumCardsAvailableToMove() const;
    int moveForward();
    void moveBackward(int numCards);
    bool hasCoveredCards() const;
    bool hasCards() const;
    void accept(MoveOriginVisitor* v);
    void acceptStockVisitor(StockVisitor* visitor);
};

#endif /* SRC_MODEL_PROXY_INC_STOCKPROXY_H_ */
