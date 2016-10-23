/*
 * Move.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVE_H_
#define SRC_MODEL_INC_MOVE_H_

#include <ForwardGameAction.h>
#include <ForwardGameActionVisitor.h>
#include <MoveOrigin.h>
#include <MoveDest.h>

class Move : public ForwardGameAction {
private:
    MoveOrigin* origin;
    MoveDest* dest;
protected:
    void forwardAction();
public:
    Move(ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
        ForwardGameAction(o),
        origin(nullptr),
        dest(nullptr) {}
    void setOrigin(MoveOrigin* o);
    void setDest(MoveDest* d);
    bool canBeDone();
    void undoAction();
    ForwardGameActionPtr duplicate();
    void accept(ForwardGameActionVisitor* visitor);
    void acceptOriginVisitor(MoveOriginVisitor* origVisitor);
    void acceptDestVisitor(MoveDestVisitor* destVisitor);
};

#endif /* SRC_MODEL_INC_MOVE_H_ */
