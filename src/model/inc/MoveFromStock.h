/*
 * MoveFromStock.h
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEFROMSTOCK_H_
#define SRC_MODEL_INC_MOVEFROMSTOCK_H_

#include <Move.h>
#include <Stock.h>

class MoveFromStock: public Move {
private:
    Stock* origin;
protected:
    MoveOrigin* getMoveOrigin();
public:
    MoveFromStock(Stock* s, ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
        Move(o),
        origin(s) {}
    ForwardGameActionPtr duplicate();
    void acceptMoveVisitor(MoveVisitor* visitor);
};

#endif /* SRC_MODEL_INC_MOVEFROMSTOCK_H_ */
