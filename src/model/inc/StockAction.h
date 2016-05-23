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

class StockAction: public GameAction {
public:
    GameActionPtr duplicate();
    void accept(GameActionVisitor* actionVisitor);
};

#endif /* SRC_INC_STOCKACTION_H_ */
