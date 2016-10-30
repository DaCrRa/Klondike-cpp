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
#include <MoveVisitor.h>

#include <memory>

class Move;
typedef std::shared_ptr<Move> MovePtr;

class Move : public ForwardGameAction {
private:
    MoveDest* dest;
protected:
    virtual MoveOrigin* getMoveOrigin() = 0;
    virtual void forwardAction();
    virtual void undoImpl();
public:
    Move(ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
        ForwardGameAction(o),
        dest(nullptr) {}
    void setDest(MoveDest* d);
    bool canBeDone();
    virtual ForwardGameActionPtr duplicate() = 0;
    void accept(ForwardGameActionVisitor* visitor);
    void acceptDestVisitor(MoveDestVisitor* destVisitor);
    virtual void acceptMoveVisitor(MoveVisitor* visitor) = 0;
    virtual ~Move() {}
};

#endif /* SRC_MODEL_INC_MOVE_H_ */
