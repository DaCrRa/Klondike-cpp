/*
 * MoveFromStock.h
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEFROMFOUNDATION_H_
#define SRC_MODEL_INC_MOVEFROMFOUNDATION_H_

#include <Move.h>
#include <Foundation.h>

class MoveFromFoundation: public Move {
private:
    Foundation* origin;
protected:
    MoveOrigin* getMoveOrigin();
public:
    MoveFromFoundation(Foundation* f, ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
        Move(o),
        origin(f) {}
    ForwardGameActionPtr duplicate();
    void acceptMoveVisitor(MoveVisitor* visitor);
};

#endif /* SRC_MODEL_INC_MOVEFROMFOUNDATION_H_ */
