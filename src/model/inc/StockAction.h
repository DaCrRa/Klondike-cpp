/*
 * StockAction.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_STOCKACTION_H_
#define SRC_INC_STOCKACTION_H_

#include <GameActionVisitor.h>
#include <GameAction.h>
#include <Stock.h>

class StockAction: public GameAction {
private:
    Stock* stock;
protected:
    void action();
public:
    StockAction(Stock* s) : stock(s) { }
    GameActionPtr duplicate();
    bool canBeDone();
    void undoAction();
    void accept(GameActionVisitor* actionVisitor);
};

#endif /* SRC_INC_STOCKACTION_H_ */
