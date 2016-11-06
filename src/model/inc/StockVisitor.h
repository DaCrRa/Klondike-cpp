/*
 * StockVisitor.h
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_STOCKVISITOR_H_
#define SRC_MODEL_STOCKVISITOR_H_

#include <Card.h>

class StockVisitor {
public:
    virtual void visitCoveredCard(const Card* c) = 0;
    virtual void visitWasteCard(const Card* c) = 0;
    virtual void allCoveredCardsVisited() = 0;
    virtual void allWasteCardsVisited() = 0;
    virtual ~StockVisitor() {}
};



#endif /* SRC_MODEL_STOCKVISITOR_H_ */
