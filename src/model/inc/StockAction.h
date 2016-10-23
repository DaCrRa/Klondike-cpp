/*
 * StockAction.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_STOCKACTION_H_
#define SRC_INC_STOCKACTION_H_

#include <ForwardGameAction.h>
#include <ForwardGameActionVisitor.h>
#include <Stock.h>

class StockAction: public ForwardGameAction {
private:
    Stock* stock;
protected:
    void forwardAction();
public:
    StockAction(Stock* s, ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
    	ForwardGameAction(o),
    	stock(s) { }
    ForwardGameActionPtr duplicate();
    bool canBeDone();
    void undoAction();
    void accept(ForwardGameActionVisitor* actionVisitor);
};

#endif /* SRC_INC_STOCKACTION_H_ */
